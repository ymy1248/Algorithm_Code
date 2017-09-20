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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        search(ans, path, root, sum);
        return ans;
    }

private:
    void search(vector<vector<int>> &ans, vector<int> &path, TreeNode* node, int sum) {
        path.push_back(node->val);
        if (node->left == NULL && node->right == NULL) {
            if (sum == node->val) {
                ans.push_back(path);
            } else {
                return;
            }
        }
        if (node->left != NULL) {
            vector<int> leftPath = path;
            search(ans, leftPath, node->left, sum - node->val);
        }
        if (node->right != NULL) {
            search(ans, path, node->right, sum - node->val);
        }
    }
    
};
