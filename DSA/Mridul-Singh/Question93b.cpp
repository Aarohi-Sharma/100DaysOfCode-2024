//GFG QUESTION -> Traverse All Edges And Vertices

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void DFS(int node, vector<vector<int>>& paths, vector<bool>& visited) {
        visited[node] = true;
        for (int i = 0; i < paths.size(); ++i) {
            if (paths[node][i] == 1 && !visited[i]) {
                DFS(i, paths, visited);
            }
        }
    }
    bool isConnected(vector<vector<int>>& paths) {
        int n = paths.size();
        vector<bool> visited(n, false);
        int startNode = -1;
        for (int i = 0; i < n; ++i) {
            int degree = 0;
            for (int j = 0; j < n; ++j) {
                if (paths[i][j] == 1) {
                    degree++;
                }
            }
            if (degree > 0) {
                startNode = i;
                break;
            }
        }
        if (startNode == -1) return true;
        DFS(startNode, paths, visited);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (paths[i][j] == 1 && !visited[i]) {
                    return false;
                }
            }
        }
        return true;
    }
    int isPossible(vector<vector<int>> paths) {
        int n = paths.size();
        if (!isConnected(paths)) {
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            int degree = 0;
            for (int j = 0; j < n; ++j) {
                if (paths[i][j] == 1) {
                    degree++;
                }
            }
            if (degree % 2 != 0) {
                return 0;
            }
        }
        return 1;
    }
};
