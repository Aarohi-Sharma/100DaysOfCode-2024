#include <iostream>
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
    int count = 0;
    
    int inorderTraversal(TreeNode* root) {
        //base case 
        if (root == NULL) {
            return count;
        }

        inorderTraversal(root -> left);
        count++;
        inorderTraversal(root -> right);

        return count;
    }

    int countNodes(TreeNode* root) {
        int ans = inorderTraversal(root);
        return ans;
    }
};
