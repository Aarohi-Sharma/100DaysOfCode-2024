//LEETCODE PROBLEM -> 803

#include<bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> parent, size;
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
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
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
    int getSize(int x) {
        return size[find(x)];
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();
        int totalBricks = m * n;
        UnionFind uf(totalBricks + 1);
        auto index = [&](int row, int col) {
            return row * n + col;
        };
        vector<vector<int>> gridAfterHits = grid;
        for (const auto& hit : hits) {
            gridAfterHits[hit[0]][hit[1]] = 0;
        }
        for (int j = 0; j < n; ++j) {
            if (gridAfterHits[0][j] == 1) {
                uf.unite(index(0, j), totalBricks);
            }
        }

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (gridAfterHits[i][j] == 1) {
                    if (gridAfterHits[i-1][j] == 1) uf.unite(index(i, j), index(i-1, j));
                    if (j > 0 && gridAfterHits[i][j-1] == 1) uf.unite(index(i, j), index(i, j-1));
                }
            }
        }
        vector<int> result(hits.size());
        for (int i = hits.size() - 1; i >= 0; --i) {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] == 0) continue;
            int prevRoofSize = uf.getSize(totalBricks);
            gridAfterHits[r][c] = 1;
            if (r == 0) uf.unite(index(r, c), totalBricks);
            for (const auto& dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && gridAfterHits[nr][nc] == 1) {
                    uf.unite(index(r, c), index(nr, nc));
                }
            }
            int newRoofSize = uf.getSize(totalBricks);
            result[i] = max(0, newRoofSize - prevRoofSize - 1);
        }
        return result;
    }
};
