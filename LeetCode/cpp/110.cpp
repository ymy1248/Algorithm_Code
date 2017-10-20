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
    bool isBalanced(TreeNode* root) {
        if (height(root) == -1) {
            return false;
        } else {
            return true;
        }
    }
    
    int height(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);
        if (left == -1 || right == -1) {
            return -1;
        }
        int diff = abs(left - right);
        if (diff <= 1) {
            int max = left > right ? left : right;
            return max + 1;
        } else {
            return -1;
        }
    }
};
