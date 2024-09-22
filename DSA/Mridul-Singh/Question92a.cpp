//LEETCODE PROBLEM -> 990

#include<bits/stdc++.h>
 using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        for (string eq : equations) {
            if (eq[1] == '=') {
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';
                unionSet(x, y);
            }
        }
        for (string eq : equations) {
            if (eq[1] == '!') {
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';
                if (find(x) == find(y)) {
                    return false;
                }
            }
        }
        return true;
    }
};