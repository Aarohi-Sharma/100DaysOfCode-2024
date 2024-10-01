//LEETCODE PROBLEM -> 781

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        int result = 0;
        for (int ans : answers) {
            count[ans]++;
        }
        for (auto& [ans, cnt] : count) {
            int groupSize = ans + 1;
            int groups = (cnt + groupSize - 1) / groupSize;
            result += groups * groupSize;
        }
        return result;
    }
};