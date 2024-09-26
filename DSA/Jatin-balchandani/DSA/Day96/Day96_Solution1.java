import java.util.*;
public class Day96_Solution1 {
    {
        class Solution {

            public boolean dfs(int[] assigned, boolean[] seen, int candidate, int jobs, int applicants, int[][] G) {

                for (int i = 0; i < jobs; i++) {

                    if (G[i][candidate] == 1 && seen[i] == false) {

                        seen[i] = true;

                        //Either no applicant is assigned to that job or we can change the applicant assigned to the
                        //ith job
                        if (assigned[i] == -1 || dfs(assigned, seen, assigned[i], jobs, applicants, G)) {
                            assigned[i] = candidate;
                            return true;
                        }


                    }
                }

                return false;
            }

            public int maximumMatch(int[][] G) {
                int jobs = G.length;
                int applicant = G[0].length;

                //Which applicant is assigned to a particular job
                int[] assigned = new int[jobs];

                Arrays.fill(assigned, -1);

                int count = 0;

                //Can a job be given to ith applicant
                for (int i = 0; i < applicant; i++) {

                    boolean[] seen = new boolean[jobs];

                    if (dfs(assigned, seen, i, jobs, applicant, G)) {
                        count++;
                    }
                }

                return count;
            }}
        }}
