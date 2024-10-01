//LEETCODE PROBLEM -> 954

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        sort(arr.begin(), arr.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        for (int num : arr) {
            if (freq[num] == 0) {
                continue;
            }
            if (freq[num * 2] == 0) {
                return false;
            }
            freq[num]--;
            freq[num * 2]--;
        }
        return true;
    }
};