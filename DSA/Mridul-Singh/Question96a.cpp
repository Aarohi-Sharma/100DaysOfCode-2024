//GFG QUESTION -> Maximum Bipartite Matching

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bpm(int applicant, vector<vector<int>>& G, vector<bool>& visited, vector<int>& match) {
        int N = G[0].size();
        for (int job = 0; job < N; job++) {
            if (G[applicant][job] == 1 && !visited[job]) {
                visited[job] = true;
                if (match[job] == -1 || bpm(match[job], G, visited, match)) {
                    match[job] = applicant;
                    return true;
                }
            }
        }
        return false;
    }
    int maximumMatch(vector<vector<int>>& G) {
        int M = G.size();
        int N = G[0].size();
        vector<int> match(N, -1);
        int result = 0;
        for (int applicant = 0; applicant < M; applicant++) {
            vector<bool> visited(N, false);
            if (bpm(applicant, G, visited, match)) {
                result++;
            }
        }
        return result;
    }
};
