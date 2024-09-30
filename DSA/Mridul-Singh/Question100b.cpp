//LEETCODE PROBLEM -> 560

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumFreq;
        sumFreq[0] = 1;
        int sum = 0;
        int count = 0;
        for (int num : nums) {
            sum += num;
            if (sumFreq.find(sum - k) != sumFreq.end()) {
                count += sumFreq[sum - k];
            }
            sumFreq[sum]++;
        }
        return count;
    }
};
