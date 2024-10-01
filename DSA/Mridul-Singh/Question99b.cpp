//LEETCODE PROBLEM -> 871

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxHeap;
        int currentFuel = startFuel;
        int stops = 0;
        int prevPos = 0;
        stations.push_back({target, 0});
        for (const auto& station : stations) {
            int stationPos = station[0];
            int stationFuel = station[1];
            currentFuel -= (stationPos - prevPos);
            while (!maxHeap.empty() && currentFuel < 0) {
                currentFuel += maxHeap.top();
                maxHeap.pop();
                stops++;
            }
            if (currentFuel < 0) {
                return -1;
            }
            maxHeap.push(stationFuel);
            prevPos = stationPos;
        }
        return stops;
    }
};