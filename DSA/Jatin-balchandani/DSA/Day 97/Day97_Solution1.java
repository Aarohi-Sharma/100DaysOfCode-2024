import java.util.*;
    class GraphNode {
        int val;
        ArrayList<Integer> neighbors;

        public GraphNode(int n) {
            this.val = n;
            this.neighbors = new ArrayList();
        }

        public void addNodes(int n) {
            this.neighbors.add(n);
        }
    }
    public class Day97_Solution1 {

        public int largestPathValue(String colors, int[][] edges) {
            int n = colors.length();
            int m = edges.length;
            GraphNode graph[] = new GraphNode[n];
            int count[][] = new int[n][26];
            int indegree[] = new int[n];
            for (int i = 0; i < n; i++) {
                graph[i] = new GraphNode(i);
            }
            for (int edge[] : edges) {
                int src = edge[0];
                int dest = edge[1];
                graph[src].addNodes(dest);
                indegree[dest]++;
            }

            Queue<Integer> queue = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                if (indegree[i] == 0) {
                    queue.add(i);
                }
                count[i][colors.charAt(i) - 'a'] = 1;
            }

            int maxLength = 0;
            int visited = 0;
            while (!queue.isEmpty()) {
                int curr = queue.poll();
                visited++;
                for (int neighbor : graph[curr].neighbors) {
                    for (int i = 0; i < 26; i++) {
                        count[neighbor][i] = Math.max(count[neighbor][i], count[curr][i] + (colors.charAt(neighbor) - 'a' == i ? 1 : 0));
                    }
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 0) {
                        queue.add(neighbor);
                    }
                }
                maxLength = Math.max(maxLength, Arrays.stream(count[curr]).max().getAsInt());
            }
            return visited == n ? maxLength : -1;
        }
    }

