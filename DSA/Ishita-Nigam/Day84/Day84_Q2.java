import java.util.*;

public class Day84_Q2 {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String, Integer> map = new HashMap<>();
        int ind = 0;

        // Build the mapping from variable to index
        for (List<String> l : equations) {
            if (!map.containsKey(l.get(0))) {
                map.put(l.get(0), ind++);
            }
            if (!map.containsKey(l.get(1))) {
                map.put(l.get(1), ind++);
            }
        }

        int n = ind;
        double[][] dist = new double[n][n];
        
        // Initialize the distance matrix
        for (double[] arr : dist) {
            Arrays.fill(arr, Double.MAX_VALUE);
        }

        // Fill the distance matrix with direct relationships
        ind = 0;
        for (List<String> l : equations) {
            int u = map.get(l.get(0));
            int v = map.get(l.get(1));
            double val = values[ind++];
            dist[u][v] = val;
            dist[v][u] = 1 / val;
        }

        // Floyd-Warshall algorithm to find all pairs of shortest paths
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != k && j != k) {
                        if (dist[i][k] != Double.MAX_VALUE && dist[k][j] != Double.MAX_VALUE) {
                            dist[i][j] = Math.min(dist[i][j], dist[i][k] * dist[k][j]);
                        }
                    }
                }
            }
        }

        // Prepare the results for each query
        double[] res = new double[queries.size()];
        ind = 0;
        for (List<String> q : queries) {
            if (map.containsKey(q.get(0)) && map.containsKey(q.get(1))) {
                int u = map.get(q.get(0));
                int v = map.get(q.get(1));
                if (dist[u][v] == Double.MAX_VALUE) {
                    res[ind++] = -1.0;
                } else {
                    res[ind++] = dist[u][v];
                }
            } else {
                res[ind++] = -1.0;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Day84_Q2 solution = new Day84_Q2();
        // Example usage:
        List<List<String>> equations = Arrays.asList(
            Arrays.asList("a", "b"),
            Arrays.asList("b", "c")
        );
        double[] values = {2.0, 3.0};
        List<List<String>> queries = Arrays.asList(
            Arrays.asList("a", "c"),
            Arrays.asList("b", "a"),
            Arrays.asList("a", "e"),
            Arrays.asList("a", "a"),
            Arrays.asList("x", "x")
        );

        double[] results = solution.calcEquation(equations, values, queries);
        System.out.println(Arrays.toString(results)); // Output: [6.0, 0.5, -1.0, 1.0, -1.0]
    }
}
