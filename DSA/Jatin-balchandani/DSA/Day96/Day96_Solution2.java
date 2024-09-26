import java.util.*;
public class Day96_Solution2 {
        private static final int[] EMPTY_LIST = new int[0];

        public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
            int[] result = new int[n];
            int resultIdx = 0;
            if (n == 1)  return new int[]{0};

            // Convert all "no group" items (items with group number -1) to
            // their own group number, which increases the value of m.
            for (int groupIdx = 0; groupIdx < group.length; groupIdx++)
                if (group[groupIdx] < 0)
                    group[groupIdx] = m++;

            // Define group data structures to hold "before" ordering between
            // groups.
            List<Integer>[] groupTos = new List[m];
            List<Integer>[] groupItems = new List[m];
            for (int i = 0; i < m; i++) {
                groupTos[i] = new ArrayList<Integer>();
                groupItems[i] = new ArrayList<Integer>();
            }
            int[] groupInternalItemLinkCount = new int[m];
            int[] groupFromCounts = new int[m];

            // Define item data structures to hold "before" ordering of items
            // that are in the same group.  If a "before" ordering is for
            // items in different groups, then store that "before" order in
            // the group data structures above.  The item data structures below
            // are ONLY for items that are within the same group.
            List<Integer>[] itemTos = new List[n];
            for (int i = 0; i < n; i++)
                itemTos[i] = new ArrayList<Integer>();
            int[] itemFromCounts = new int[n];

            // Process the passed beforeItems data, converting it to group order
            // links when the items are in different groups, or item order links
            // if the items are within the same group.
            int itemIdx = 0;
            int beforeCount = 0;
            for (List<Integer> befores : beforeItems) {
                int itemGroupNum = group[itemIdx];
                groupItems[itemGroupNum].add(itemIdx);
                beforeCount += befores.size();
                for (int before : befores) {
                    int beforeGroupNum = group[before];
                    if (itemGroupNum == beforeGroupNum) {   // If both items in same group.
                        groupInternalItemLinkCount[itemGroupNum]++;
                        itemTos[before].add(itemIdx);
                        itemFromCounts[itemIdx]++;
                    } else {                                // Both items in different groups.
                        groupTos[beforeGroupNum].add(itemGroupNum);
                        groupFromCounts[itemGroupNum]++;
                    }
                }
                itemIdx++;
            }

            // If there aren't any "before" dependencies, then simply return all
            // items in ascending numerical order.
            if (beforeCount == 0) {
                for (int i = 0; i < n; i++)  result[i] = i;
                return result;
            }

            // Do a topological sort using Kahn's algorithm, of the groups (but
            // not the items within the groups).
            int[] groupResult = new int[m];
            int groupResultIdx = 0;
            int[] indyGroups = new int[m];
            int indyGroupsInnIdx = 0;
            int indyGroupsOutIdx = 0;
            for (int i = 0; i < m; i++)
                if (groupFromCounts[i] == 0)
                    indyGroups[indyGroupsOutIdx++] = i;
            while (indyGroupsInnIdx < indyGroupsOutIdx) {
                int grp = indyGroups[indyGroupsInnIdx++];
                groupResult[groupResultIdx++] = grp;
                for (int grpTo : groupTos[grp])
                    if (--groupFromCounts[grpTo] == 0)
                        indyGroups[indyGroupsOutIdx++] = grpTo;
            }
            if (groupResultIdx != m)    // If not all groups used, then must be
                return EMPTY_LIST;      //    cycles in the "before" dependencies.

            // Sort items within each group.  We now have the order of the groups.
            // So now process the groups in output order, and do a topological
            // sort on the items within each group, if needed.
            int[] indyItems = new int[n];
            for (groupResultIdx = 0; groupResultIdx < m; groupResultIdx++) {
                int grp = groupResult[groupResultIdx];
                // If no dependencies on items within the group, then output the
                // groups items without any sorting.
                if (groupInternalItemLinkCount[grp] == 0) {
                    for (int itm : groupItems[grp])
                        result[resultIdx++] = itm;
                }
                // Else items in group have some "before" dependencies, so do a
                // topological sort on the group's items.  Output sorted item
                // numbers as part of this leetcode problem's result.
                else {
                    int indyItemsInnIdx = 0;
                    int indyItemsOutIdx = 0;
                    int startResultIdx = resultIdx;
                    for (int itm : groupItems[grp])
                        if (itemFromCounts[itm] == 0)
                            indyItems[indyItemsOutIdx++] = itm;
                    while (indyItemsInnIdx < indyItemsOutIdx) {
                        int itm = indyItems[indyItemsInnIdx++];
                        result[resultIdx++] = itm;
                        for (int itmTo : itemTos[itm])
                            if (--itemFromCounts[itmTo] == 0)
                                indyItems[indyItemsOutIdx++] = itmTo;
                    }
                    // If not all items within current group have been output,
                    // then there must be cycles in the "before" dependencies.
                    if (resultIdx - startResultIdx != groupItems[grp].size())
                        return EMPTY_LIST;
                }
            }

            return result;
        }
    }
