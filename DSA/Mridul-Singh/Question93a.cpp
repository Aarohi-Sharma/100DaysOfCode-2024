//LEETCODE PROBLEM 685

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    class UnionFind {
    public:
        vector<int> parent, rank;
        UnionFind(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            for (int i = 0; i <= n; ++i) {
                parent[i] = i;
            }
        }
        int find(int u) {
            if (parent[u] != u) {
                parent[u] = find(parent[u]);
            }
            return parent[u];
        }

        bool unionSets(int u, int v) {
            int rootU = find(u);
            int rootV = find(v);
            if (rootU == rootV) {
                return false;
            }
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            return true;
        }
    };

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i) parent[i] = i;
        vector<int> candidate1, candidate2;
        UnionFind uf(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (parent[v] != v) {
                candidate1 = {parent[v], v};
                candidate2 = {u, v};
                edge[1] = 0;
            } else {
                parent[v] = u;
            }
        }
        for (auto& edge : edges) {
            if (edge[1] == 0) continue;
            if (!uf.unionSets(edge[0], edge[1])) {
                if (candidate1.empty()) {
                    return edge;
                }
                return candidate1;
            }
        }
        return candidate2;
    }
};