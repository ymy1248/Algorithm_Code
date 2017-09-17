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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode> s;
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        TreeNode* p = root;
        
        s.push(*root);
        
        while (!s.empty()) {
            TreeNode& node = s.top();
            
            if (node.left != NULL) {
                s.push(*node.left);
                node.left = NULL;
                continue;
            }
            s.pop();
            ans.push_back(node.val);
            
            if (node.right != NULL) {
                s.push(*node.right);
            }
        }
        return ans;
    }
};
