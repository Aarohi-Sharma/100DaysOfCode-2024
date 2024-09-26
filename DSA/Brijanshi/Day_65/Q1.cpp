#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i=0; i<position.size(); ++i) {
            pair.push_back({position[i], speed[i]});
        }

        // Sort the pairs by position in descending order
        sort(pair.begin(), pair.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        stack<double> stacl;
        for (const auto& [p, s] : pair) {
            double time = static_cast<double>(target - p) / s;
            if (!stacl.empty() && time <= stacl.top()) {
                continue;
            }
            stacl.push(time);
        }

        return stacl.size();
    }
};
