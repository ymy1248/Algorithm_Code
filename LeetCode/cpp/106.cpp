
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) {
            return NULL;
        }
        TreeNode* root = build(postorder, inorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
        return root;
    }
    
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int inlo, int inhi, int poslo, int poshi) {
        if (inhi < inlo || inhi >= postorder.size() || inlo < 0) {
            return NULL;
        }
        int nodeVal = postorder[poshi];
        TreeNode* node = new TreeNode(nodeVal);
        int index = 0;
        for (int i = inlo; i <= inhi; ++i) {
            if (inorder[i] == nodeVal) {
                index = i;
                break;
            }
        }
        int leftLen = index - inlo;
        node->left = build(postorder, inorder, inlo, inlo + leftLen - 1, poslo, poslo + leftLen - 1);
        node->right = build(postorder, inorder, inlo + leftLen + 1, inhi, poslo + leftLen, poshi - 1);
        return node;
    }
};
