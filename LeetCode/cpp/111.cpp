/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return foo(root);
    }
    
    int foo(TreeNode *node) {
        if (node == NULL) {
            return INT_MAX;
        }
        if (node->left == NULL && node->right == NULL) {
            return 1;
        }
        int left = foo(node->left);
        int right = foo(node->right);
        if (left < right) {
            return left + 1;
        } else {
            return right + 1;
        }
    }
};
