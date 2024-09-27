//LEETCODE PROBLEM -> 1857

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        vector<vector<int>> dp(n, vector<int>(26, 0));
        int nodesProcessed = 0;
        int maxColorValue = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            nodesProcessed++;
            dp[node][colors[node] - 'a']++;
            maxColorValue = max(maxColorValue, dp[node][colors[node] - 'a']);
            for (int neighbor : adj[node]) {
                for (int c = 0; c < 26; c++) {
                    dp[neighbor][c] = max(dp[neighbor][c], dp[node][c]);
                }
                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return (nodesProcessed == n) ? maxColorValue : -1;
    }
};