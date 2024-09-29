import java.util.*;

public class Day100_solution1 {
        public int[][] kClosest(int[][] points, int k) {
            // here we got to sort and return the k closest points or pairs to origin (0,0)
            // we can compare this problem to topKfrequent elements, rankScores, topKfrequent words etc
            // so a PriorityQueue is efficient in this case
            // the idea is, we are going to insert an array of size 3 sorted by distance: dist, x co-ordinate, y co-ordinate.

            int[][] res = new int[k][2]; // result is [][] and we return only k pairs thats why [k][2]
            Queue<int[]> pq = new PriorityQueue<>(Comparator.comparing(a->a[0]));// sort dist or a[0] in asc order

            for (int[] point : points){
                int dist = (point[0]*point[0])+(point[1]*point[1]); // (x-0)^2 is x^2 and (y-0)^2 is y^2
                pq.offer(new int[]{dist, point[0], point[1]}); // it's an integer array inside a queue
            }

            for (int i=0; i<k; i++){
                int[] point = pq.poll();
                res[i] = new int[]{point[1], point[2]}; // adding only x, y co-ordinates
            }

            return res;

        }
    }
