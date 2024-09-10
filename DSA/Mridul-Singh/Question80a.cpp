//LEETCODE PROBLEM -> 297

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        string val;
        stringstream ss(data);
        while (getline(ss, val, ',')) {
            nodes.push(val);
        }
        return buildTree(nodes);
    }

private:
    TreeNode* buildTree(queue<string>& nodes) {
        string val = nodes.front();
        nodes.pop();
        if (val == "#") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(val));
        root->left = buildTree(nodes);
        root->right = buildTree(nodes);
        return root;
    }
};
