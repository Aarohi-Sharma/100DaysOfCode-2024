public class Day31_Solution2 {
        public int numSubarrayBoundedMax(int[] nums, int left, int right) {
            int count=0, ans=0, i=0,j=0;
            int n = nums.length;

            while(j<n){
                if(nums[j]>right){
                    count =0;
                    i = j+1;

                }
                else if(nums[j] >= left && nums[j]<= right){
                    count = j-i+1;
                }
                ans += count;
                j++;
            }
            return ans;
        }
    }

