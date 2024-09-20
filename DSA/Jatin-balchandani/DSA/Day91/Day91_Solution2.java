
import java.util.*;
public class Day91_Solution2 {
    // Algo used Topological Sort
//Same as Course Schedule 1 , just here we are returining topo as an array
        public int[] findOrder(int numCourses, int[][] prerequisites) {
            ArrayList<ArrayList<Integer>> adj= new ArrayList<>();// creating our adj list
            for(int i= 0; i< numCourses; i++){
                adj.add(new ArrayList<>());
            }

            int m = prerequisites.length; // converting the input prerequisites to adjList Step1
            for(int i=0;i<m;i++){
                adj.get(prerequisites[i][1]).add(prerequisites[i][0]);
            }

            int[] indegree= new int[numCourses]; // indegree array

            for(int i=0; i< numCourses; i++){   // marking the incoming edges (incoming edges) of node node Step2
                for(int it: adj.get(i)){
                    indegree[it]++;
                }
            }

            Queue<Integer> q= new LinkedList<>();
            int[] topo= new int[numCourses];    // topo sort list
            int index=0;
            for(int i=0; i< numCourses; i++){   // // getting the nodes with 0 in-degree Step3
                if(indegree[i]== 0){
                    q.add(i);
                }
            }

            while(!q.isEmpty()){    // doing our Topo sort BFS(Kahn's) Step4
                int node= q.poll();
                topo[index++]= node;
                for(int it: adj.get(node)){
                    indegree[it]--; // removing the edges for the node nodes added in queue
                    if(indegree[it] == 0){  // if at any point the node who are becoming 0 after decreaising then add in queue
                        q.add(it);
                    }
                }
            }
            if(numCourses == index) return topo;
            int[] res= {};
            return res;

        }

}
