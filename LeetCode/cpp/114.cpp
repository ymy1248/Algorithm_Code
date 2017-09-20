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
    void flatten(TreeNode* root) {
        p = new TreeNode(0);
        flat(root);
    }
    
    void flat(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        node->left = NULL;
        p->right = node;
        p = p->right;
        flat(left);
        flat(right);
    }
private:
    TreeNode* p;
};