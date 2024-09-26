//LEETCODE PROBLEM -> 947

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(int x, unordered_map<int, int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }

    void unite(int x, int y, unordered_map<int, int>& parent, unordered_map<int, int>& rank) {
        int rootX = find(x, parent);
        int rootY = find(y, parent);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;
        for (const auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10000;
            if (parent.find(row) == parent.end()) parent[row] = row;
            if (parent.find(col) == parent.end()) parent[col] = col;
            unite(row, col, parent, rank);
        }
        unordered_map<int, int> components;
        for (const auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10000;
            components[find(row, parent)]++;
        }
        return stones.size() - components.size();
    }
};