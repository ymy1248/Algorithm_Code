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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        queue<TreeNode*> treeQueue;
        
        treeQueue.push(root);
        
        while (!treeQueue.empty()) {
            TreeNode* node = treeQueue.front();
            treeQueue.pop();
            if (node->left == NULL && node->right == NULL) {
                if (node->val == sum) {
                    return true;
                }
                continue;
            }
            if (node->left != NULL) {
                node->left->val = node->val + node->left->val;
                treeQueue.push(node->left);
            }
            if (node->right != NULL) {
                node->right->val = node->val + node->right->val;
                treeQueue.push(node->right);
            }
        }
        return false;
    }
};
