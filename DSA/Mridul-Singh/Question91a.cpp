//GFG Questions -> Doctor Strange

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int u, vector<vector<int>>& graph, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<bool>& ap, int& time) {
        int children = 0;
        disc[u] = low[u] = ++time;
        for (int v : graph[u]) {
            if (disc[v] == -1) {
                children++;
                parent[v] = u;
                dfs(v, graph, disc, low, parent, ap, time);
                low[u] = min(low[u], low[v]);

                if (parent[u] == -1 && children > 1) {
                    ap[u] = true;
                }

                if (parent[u] != -1 && low[v] >= disc[u]) {
                    ap[u] = true;
                }
            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    int doctorStrange(int N, int M, vector<vector<int>>& graph) {
        vector<int> disc(N, -1), low(N, -1), parent(N, -1);
        vector<bool> ap(N, false);
        int time = 0;
        for (int i = 0; i < N; i++) {
            if (disc[i] == -1)
                dfs(i, graph, disc, low, parent, ap, time);
        }
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (ap[i])
                count++;
        }
        return count;
    }
};

int main() {
    int N = 5, M = 5;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 2}, {3, 4}, {5, 4}};
    vector<vector<int>> graph(N);
    for (auto& edge : edges) {
        graph[edge[0] - 1].push_back(edge[1] - 1);
        graph[edge[1] - 1].push_back(edge[0] - 1);
    }
    Solution sol;
    cout << sol.doctorStrange(N, M, graph) << endl;
    return 0;
}
