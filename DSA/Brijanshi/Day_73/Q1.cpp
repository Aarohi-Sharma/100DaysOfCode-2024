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
    int count(TreeNode* root, int x, int &lc, int &rc) {
        if (root == NULL) {
            return 0;
        }

        int left = count(root->left, x, lc, rc);
        int right = count(root->right, x, lc, rc);
        if(root->val == x) {
            lc = left;
            rc = right;
        }

        return left+right+1;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int lc = 0, rc = 0;
        count(root, x, lc, rc);

        int nnpex = n - (lc+rc+1);
        int maxi = max(nnpex, max(lc, rc));

        return maxi>(n/2);
    }
};
