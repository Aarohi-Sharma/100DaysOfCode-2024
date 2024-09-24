//LEETCODE PROBLEM -> 332

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> result;
    void dfs(const string& airport) {
        auto& destinations = graph[airport];
        while (!destinations.empty()) {
            string next = destinations.top();
            destinations.pop();
            dfs(next);
        }
        result.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }
        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};
