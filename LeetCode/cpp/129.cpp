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
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return sum(root, 0);
    }
    
    int sum(TreeNode* node, int n) {
        n = n * 10 + node->val;
        if (node->left != NULL && node->right != NULL) {
            return sum(node->left, n) + sum(node->right, n);
        }
        if (node->left == NULL && node->right != NULL) {
            return sum(node->right, n);
        }
        if (node->left != NULL && node->right == NULL) {
            return sum(node->left, n);
        }
        return n;
    }
};