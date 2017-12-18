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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> _queue;
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        _queue.push(root);
        _queue.push(nullptr);
        TreeNode* last = root;
        
        while(_queue.size() != 1) {
            TreeNode* node = _queue.front();
            _queue.pop();
            if (node == nullptr) {
                ans.push_back(last->val);
                _queue.push(nullptr);
            } else {
                // cout << node->val << endl;
                if (node->left != NULL) {
                    _queue.push(node->left);
                }
                if (node->right != NULL) {
                    _queue.push(node->right);
                }
                last = node;
            }
        }
        ans.push_back(last->val);
        return ans;
    }
};
