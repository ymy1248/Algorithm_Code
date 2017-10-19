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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> _queue;
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        _queue.push(root);
        _queue.push(NULL);
        
        vector<int> level;
        while(!_queue.empty()) {
            TreeNode *node = _queue.front();
            _queue.pop();
            if (node == NULL) {
                if (_queue.size() > 0) {
                    _queue.push(NULL);
                }
                ans.insert(ans.begin(), level);
                level.clear();
            } else {
                level.push_back(node->val);
                if (node->left != NULL) {
                    _queue.push(node->left);
                }
                if (node->right != NULL) {
                    _queue.push(node->right);
                }
            }
        }
        return ans;
    }
};
