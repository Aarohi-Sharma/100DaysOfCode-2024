import java.util.*;

class Pair {
    int node, lev;

    Pair(int node, int lev) {
        this.node = node;
        this.lev = lev;
    }
}

public class Day84_Q1 {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target)
            return 0;

        HashMap<Integer, Set<Integer>> map = new HashMap<>();
        Queue<Pair> q = new LinkedList<>();
        Set<Integer> vis_stops = new HashSet<>();

        for (int i = 0; i < routes.length; i++) {
            Set<Integer> temp = new HashSet<>();
            for (int it : routes[i])
                temp.add(it);
            map.put(i, temp);
        }

        HashMap<Integer, Set<Integer>> stop_bus = new HashMap<>();

        for (int i = 0; i < routes.length; i++) {
            for (int it : routes[i]) {
                stop_bus.computeIfAbsent(it, k -> new HashSet<>()).add(i);
            }
        }

        q.add(new Pair(source, 1));
        while (!q.isEmpty()) {
            int node = q.peek().node;
            int lev = q.peek().lev;
            q.remove();
            Set<Integer> vis_bus = new HashSet<>();

            for (int bus : stop_bus.getOrDefault(node, new HashSet<>())) {
                if (map.get(bus).contains(target))
                    return lev;

                if (!vis_bus.contains(bus)) {
                    vis_bus.add(bus);
                    for (int it : map.get(bus)) {
                        if (!vis_stops.contains(it)) {
                            q.add(new Pair(it, lev + 1));
                        }
                    }
                    vis_stops.add(bus);
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Day84_Q1 solution = new Day84_Q1();
        // Example usage:
        int[][] routes = {{1, 2, 7}, {3, 6, 7}};
        int source = 1;
        int target = 6;
        System.out.println(solution.numBusesToDestination(routes, source, target)); // Output: 2
    }
}
