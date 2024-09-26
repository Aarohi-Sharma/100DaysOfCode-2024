#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
    
        unordered_map<int, int> bottomNode; // Use unordered_map for faster access
        queue<pair<Node*, int>> q;
        int minHD = 0, maxHD = 0; // Track the range of horizontal distances
    
        q.push({root, 0});
    
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
    
            bottomNode[hd] = frontNode->data;
    
            // Track the min and max horizontal distances
            if (hd < minHD) minHD = hd;
            if (hd > maxHD) maxHD = hd;
    
            if (frontNode->left) {
                q.push({frontNode->left, hd - 1});
            }
    
            if (frontNode->right) {
                q.push({frontNode->right, hd + 1});
            }
        }
    
        // Generate the result based on the horizontal distance range
        for (int i = minHD; i <= maxHD; ++i) {
            ans.push_back(bottomNode[i]);
        }
    
        return ans;
    }
};
