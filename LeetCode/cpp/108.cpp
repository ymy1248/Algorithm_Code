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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return foo(nums, 0, nums.size() - 1);
    }
    
    TreeNode* foo(vector<int> &nums, int lo, int hi) {
        // cout << lo << "," << hi << endl;
        if (lo > hi) {
            return NULL;
        }
        size_t mid = (lo + hi) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = foo(nums, lo, mid - 1);
        node->right = foo(nums, mid + 1, hi);
        return node;
    }
};
