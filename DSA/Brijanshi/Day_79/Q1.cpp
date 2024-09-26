#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void createMapping(vector<int>& inorder, map<int, int> &nodeToIndex, int n) {
        for (int i=0; i<n; i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }

    TreeNode* solve (vector<int>& inorder, vector<int>& postorder, int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex) {
        //base case
        if (index < 0 || inorderStart > inorderEnd) {
            return NULL;
        }

        //create a root node for element
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);

        //find element's index in inorder
        int position = nodeToIndex[element];

        root -> right = solve(inorder, postorder, index, position+1, inorderEnd, n, nodeToIndex);
        root -> left = solve(inorder, postorder, index, inorderStart, position-1, n, nodeToIndex);

        return root;    
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postOrderIndex = n-1;
        map <int, int> nodeToIndex;
        //create nodes to index mapping
        createMapping(inorder, nodeToIndex, n);

        TreeNode* ans = solve(inorder, postorder, postOrderIndex, 0, n-1, n, nodeToIndex);
        return ans;
    }
};
