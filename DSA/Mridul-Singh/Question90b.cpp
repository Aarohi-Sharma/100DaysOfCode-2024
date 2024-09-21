//GFG Question -> Eulerian Path in an Undirected Graph

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int eulerPath(int N, vector<vector<int>> graph){
        // code here
        int n = graph.size();
        int oddCount = 0;
        for (int i = 0; i < n; i++) {
            int degree = 0;
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 1) {
                    degree++;
                }
            }
            if (degree % 2 != 0) {
                oddCount++;
            }
        }
        return (oddCount == 0 || oddCount == 2);
    }
};