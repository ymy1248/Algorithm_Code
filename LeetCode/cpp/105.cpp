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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }
        TreeNode* root = build(preorder, inorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
        return root;
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inlo, int inhi, int prelo, int prehi) {
        if (inhi < inlo || inhi >= preorder.size() || inlo < 0) {
            return NULL;
        }
        int nodeVal = preorder[prelo];
        TreeNode* node = new TreeNode(nodeVal);
        int index = 0;
        for (int i = inlo; i <= inhi; ++i) {
            if (inorder[i] == nodeVal) {
                index = i;
                break;
            }
        }
        int leftLen = index - inlo;
        node->left = build(preorder, inorder, inlo, inlo + leftLen - 1, prelo + 1, prelo + leftLen);
        node->right = build(preorder, inorder, inlo + leftLen + 1, inhi, prelo + leftLen + 1, prehi);
        return node;
    }
};
