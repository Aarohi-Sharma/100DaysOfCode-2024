import java.util.*;

public class Day91_Solution1 {

        // Function for finding maximum and value pair
        public static int doctorStrange (int n, int k, int g[][]) {
            //construct the graph;
            ArrayList<Integer>[] graph = new ArrayList[n+1];
            for (int i = 1; i <=n; i++){
                graph[i] = new ArrayList<>();
            }

            for (int[] br: g){
                int u = br[0];
                int v = br[1];

                graph[u].add(v);
                graph[v].add(u);
            }

            int[] disc = new int[n+1];
            Arrays.fill(disc, -1);
            int[] low = new int[n+1];
            int time = 0;

            boolean[] ap = new boolean[n+1];
            int rootcalls = 0;
            for (int i = 1; i <= n; i++){
                if (disc[i] == -1){
                    dfs(i, -1, disc, low, time,graph, ap, rootcalls);
                }
            }
            int tap = 0;
            if (ap[1] && rootcalls > 1){
                tap++;
            }
            for (int i = 2; i <= n; i++){
                if (ap[i]){
                    tap++;
                }
            }
            return tap;
        }

        private static void dfs(int src, int par, int[] disc, int[] low, int time,ArrayList<Integer>[] graph, boolean[] ap, int rootcalls){

            disc[src] = low[src] = time++;

            for (int nbr : graph[src]){
                if (disc[nbr] == -1){
                    if (par == -1)
                        rootcalls++;
                    dfs(nbr, src, disc, low, time, graph, ap, rootcalls);

                    if (disc[src] <= low[nbr]){
                        ap[src] = true;
                    }
                    low[src]= Math.min(low[src], low[nbr]);
                }
                else if (nbr != par){
                    low[src] = Math.min(low[src], disc[nbr]);
                }
            }
        }
    }

