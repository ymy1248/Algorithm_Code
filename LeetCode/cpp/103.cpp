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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            vector<vector<int>> a;
            return a;
        }
        stack<TreeNode*> odd;
        stack<TreeNode*> even;
        int level = 1;
        odd.push(root);
        vector<vector<int>> ans;
        
        while (!odd.empty() || !even.empty()) {
            vector<int> subans;
            if (level % 2 == 1) {
                while (!odd.empty()) {
                    TreeNode* node = odd.top();
                    subans.push_back(node->val);
                    odd.pop();
                    if (node->left != NULL) {
                        even.push(node->left);
                    }
                    if (node->right != NULL) {
                        even.push(node->right);
                    }
                }
            } else {
                while (!even.empty()) {
                    TreeNode* node = even.top();
                    subans.push_back(node->val);
                    even.pop();
                    if (node->right != NULL) {
                        odd.push(node->right);
                    }
                    if (node->left != NULL) {
                        odd.push(node->left);
                    }
                }
            }
            ans.push_back(subans);
            level++;
        }
        return ans;
    }
};
