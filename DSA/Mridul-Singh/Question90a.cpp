//GFG Question -> Euler Circuit in an Undirected Graph

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }
    int isEularCircuitExist(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        int startVertex = -1;
        for (int i = 0; i < V; i++) {
            if (adj[i].size() > 0) {
                startVertex = i;
                break;
            }
        }
        if (startVertex == -1) return 1;
        dfs(startVertex, adj, visited);
        for (int i = 0; i < V; i++) {
            if (!visited[i] && adj[i].size() > 0) {
                return 0;
            }
        }
        for (int i = 0; i < V; i++) {
            if (adj[i].size() % 2 != 0) {
                return 0;
            }
        }
        return 1;
    }
};