
    import java.util.*;

    public class Day92_Solution1 {

        // Union-Find find method with path compression
        public static int find(int[] parent, int x) {
            if (parent[x] != x) {
                parent[x] = find(parent, parent[x]); // Path compression
            }
            return parent[x];
        }

        // Union-Find union method
        public static void union(int[] parent, int x, int y) {
            int rootX = find(parent, x);
            int rootY = find(parent, y);
            if (rootX != rootY) {
                parent[rootX] = rootY; // Union operation
            }
        }

        // Function to determine if equations are possible
        public static boolean equationsPossible(String[] equations) {
            // Initialize parent array for 26 lowercase letters
            int[] parent = new int[26];
            for (int i = 0; i < 26; i++) {
                parent[i] = i; // Initially, each variable is its own parent
            }

            // First pass: process all "==" equations and union the variables
            for (String eq : equations) {
                if (eq.charAt(1) == '=') {
                    int x = eq.charAt(0) - 'a';
                    int y = eq.charAt(3) - 'a';
                    union(parent, x, y);
                }
            }

            // Second pass: check all "!=" equations and ensure no contradiction
            for (String eq : equations) {
                if (eq.charAt(1) == '!') {
                    int x = eq.charAt(0) - 'a';
                    int y = eq.charAt(3) - 'a';
                    if (find(parent, x) == find(parent, y)) {
                        return false; // Contradiction found
                    }
                }
            }

            return true; // No contradictions found
        }

        public static void main(String[] args) {
            // Example test cases
            String[] equations1 = {"a==b", "b!=a"};
            System.out.println(equationsPossible(equations1)); // Output: false

            String[] equations2 = {"b==a", "a==b"};
            System.out.println(equationsPossible(equations2)); // Output: true
        }
    }

}
