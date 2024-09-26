//GFG Question -> Find the Maximum Flow

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool bfs(vector<vector<int>>& residualGraph, int source, int sink, vector<int>& parent) {
        int n = residualGraph.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        parent[source] = -1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 1; v < n; ++v) {
                if (!visited[v] && residualGraph[u][v] > 0) {
                    if (v == sink) {
                        parent[v] = u;
                        return true;
                    }
                    q.push(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
        }
        return false;
    }
    int findMaxFlow(int N, int M, vector<vector<int>> Edges) {
        vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0));
        for (const auto& edge : Edges) {
            int u = edge[0];
            int v = edge[1];
            int capacity = edge[2];
            graph[u][v] += capacity;
        }
        vector<vector<int>> residualGraph = graph;
        vector<int> parent(N + 1);
        int maxFlow = 0;
        while (bfs(residualGraph, 1, N, parent)) {
            int pathFlow = INT_MAX;
            for (int v = N; v != 1; v = parent[v]) {
                int u = parent[v];
                pathFlow = min(pathFlow, residualGraph[u][v]);
            }
            for (int v = N; v != 1; v = parent[v]) {
                int u = parent[v];
                residualGraph[u][v] -= pathFlow;
                residualGraph[v][u] += pathFlow;
            }
            maxFlow += pathFlow;
        }
        return maxFlow;
    }
};
