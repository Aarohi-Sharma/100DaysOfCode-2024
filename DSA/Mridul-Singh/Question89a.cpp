//LEETCODE PROBLEM -> 959

#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent;
public:
    DSU(int size) {
        parent.resize(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int size = n * n * 4;
        DSU dsu(size);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int root = 4 * (i * n + j);
                if (grid[i][j] == '/') {
                    dsu.unite(root + 0, root + 3);
                    dsu.unite(root + 1, root + 2);
                } else if (grid[i][j] == '\\') {
                    dsu.unite(root + 0, root + 1);
                    dsu.unite(root + 2, root + 3);
                } else {
                    dsu.unite(root + 0, root + 1);
                    dsu.unite(root + 1, root + 2);
                    dsu.unite(root + 2, root + 3);
                }
                if (j + 1 < n) {
                    dsu.unite(root + 1, 4 * (i * n + j + 1) + 3);
                }
                if (i + 1 < n) {
                    dsu.unite(root + 2, 4 * ((i + 1) * n + j) + 0);
                }
            }
        }
        int regions = 0;
        for (int i = 0; i < size; i++) {
            if (dsu.find(i) == i) {
                regions++;
            }
        }
        return regions;
    }
};
