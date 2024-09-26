//LEETCODE PROBLEM -> 924

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[node][i] == 1 && !visited[i]) {
                dfs(i, graph, visited, component);
            }
        }
    }
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<vector<int>> components;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, graph, visited, component);
                components.push_back(component);
            }
        }
        vector<int> infectedCount(components.size(), 0);
        vector<int> componentIndex(n, -1);
        for (int i = 0; i < components.size(); ++i) {
            for (int node : components[i]) {
                componentIndex[node] = i;
            }
        }
        for (int node : initial) {
            infectedCount[componentIndex[node]]++;
        }
        int result = -1;
        int maxSaved = -1;
        sort(initial.begin(), initial.end());
        for (int node : initial) {
            int compIdx = componentIndex[node];
            if (infectedCount[compIdx] == 1) {
                int saved = components[compIdx].size();
                if (saved > maxSaved) {
                    maxSaved = saved;
                    result = node;
                }
            }
        }
        if (result == -1) {
            result = *min_element(initial.begin(), initial.end());
        }
        return result;
    }
};