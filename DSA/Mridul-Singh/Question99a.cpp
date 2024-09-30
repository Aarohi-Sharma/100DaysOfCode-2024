//LEETCODE PROBLEM -> 914

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        for (int num : deck) {
            count[num]++;
        }
        int g = -1;
        for (auto& entry : count) {
            if (g == -1) {
                g = entry.second;
            } else {
                g = gcd(g, entry.second);
            }
        }
        return g >= 2;
    }
};