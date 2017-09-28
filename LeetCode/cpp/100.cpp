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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return in(p, q);
    }

private:
    bool in(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL){
            return true;
        }
        if (p != NULL && q == NULL || p == NULL && q != NULL || p->val != q->val) {
            return false;
        }
        return in(p->left, q->left) && in(p->right, q->right);
    }
};
