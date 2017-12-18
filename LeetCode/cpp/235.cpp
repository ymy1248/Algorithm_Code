#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int left = INT_MIN, right = INT_MAX;
        while (root != NULL) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
                right = root->val - 1;
            } else if (p->val > root->val && q->val > root->val) {
                root = root->right;
                left = root->val + 1;
            } else {
                return root;
            }
        }
        return NULL;
    }
};
