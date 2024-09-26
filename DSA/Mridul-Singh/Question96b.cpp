//LEETCODE PROBLEM -> 1203

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int newGroupId = m;
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = newGroupId++;
            }
        }
        vector<vector<int>> itemGraph(n);
        vector<int> itemIndegree(n, 0);
        vector<vector<int>> groupGraph(newGroupId);
        vector<int> groupIndegree(newGroupId, 0);
        for (int i = 0; i < n; ++i) {
            int currGroup = group[i];
            for (int prev : beforeItems[i]) {
                int prevGroup = group[prev];
                itemGraph[prev].push_back(i);
                itemIndegree[i]++;
                if (currGroup != prevGroup) {
                    groupGraph[prevGroup].push_back(currGroup);
                    groupIndegree[currGroup]++;
                }
            }
        }
        vector<int> sortedItems = topologicalSort(itemGraph, itemIndegree, n);
        if (sortedItems.empty()) return {};
        vector<int> sortedGroups = topologicalSort(groupGraph, groupIndegree, newGroupId);
        if (sortedGroups.empty()) return {};
        unordered_map<int, vector<int>> groupedItems;
        for (int item : sortedItems) {
            groupedItems[group[item]].push_back(item);
        }
        vector<int> result;
        for (int g : sortedGroups) {
            for (int item : groupedItems[g]) {
                result.push_back(item);
            }
        }
        return result;
    }

private:
    vector<int> topologicalSort(vector<vector<int>>& graph, vector<int>& indegree, int totalNodes) {
        queue<int> q;
        for (int i = 0; i < totalNodes; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> sortedOrder;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            sortedOrder.push_back(node);

            for (int neighbor : graph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        if (sortedOrder.size() == totalNodes) {
            return sortedOrder;
        } else {
            return {};
        }
    }
};
