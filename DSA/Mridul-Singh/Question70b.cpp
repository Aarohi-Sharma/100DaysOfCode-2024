//LEETCODE PROBLEM 834

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tree(n);
        vector<int> res(n, 0), count(n, 1);
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        function<void(int, int)> dfs1 = [&](int node, int parent) {
            for (int neighbor : tree[node]) {
                if (neighbor == parent) continue;
                dfs1(neighbor, node);
                count[node] += count[neighbor];
                res[node] += res[neighbor] + count[neighbor];
            }
        };
        function<void(int, int)> dfs2 = [&](int node, int parent) {
            for (int neighbor : tree[node]) {
                if (neighbor == parent) continue;
                res[neighbor] = res[node] - count[neighbor] + (n - count[neighbor]);
                dfs2(neighbor, node);
            }
        };
        dfs1(0, -1);
        dfs2(0, -1);
        return res;
    }
};