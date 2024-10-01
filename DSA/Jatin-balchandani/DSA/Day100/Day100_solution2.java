public class Day100_solution2 {
        public int subarraySum(int[] nums, int k) {

            //Best: TC: O N , Prefix Sum Algo
//        map.put(0,1);   we are checking the number of sub arrays so we have to add this suppose preSum-k = 0 then we have to add 1 in count, we were not doing that in max subarray with sum k because there we just have to check the maximum ele  not the counts.

            Map<Integer, Integer> map= new HashMap<>();

            int prefixSum=0;
            int count=0;

            map.put(0,1);

            for(int i=0; i< nums.length; i++){

                prefixSum+= nums[i];
                int rem= prefixSum - k;
                if(map.containsKey(rem)){
                    count+= map.get(rem);  // adding the number of occurences of subarray sum k
                }

                map.put(prefixSum, map.getOrDefault(prefixSum, 0) + 1);
            }
            return count;

            // Brute force TC: O N , Basic two loops and basic logic
        }
    }
