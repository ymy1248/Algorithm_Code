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
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int* left = foo(root->val, root->left);
        int* right = foo(root->val, root->right);
        int max = left[1] > right[1] ? left[1] : right[1];
        int now = left[0] + right[0];
        return max > now ? max : now;
    }

private:
    int* foo(int last, TreeNode *node) {
        if (node == NULL) {
            return new int [2]{0, 0};
        }
        int* left = foo(node->val, node->left);
        int* right = foo(node->val, node->right);
        int *now = new int[2];
        // if (left[0] == 1 && right[0] == 1) {
        //     count = left[1] + right[1];
        // } else if (left[0] != 1 && right[0] == 1) {
        //     count = right[1];
        // } else if (left[0] == 1 && right[0] != 1) {
        //     count = left[1];
        // }
        
        if (last == node->val) {
            now[0] = left[0] > right[0] ? left[0] + 1 : right[0] + 1;
            now[1] = left[1] > right[1] ? left[1] : right[1];
        } else {
            int max = left[1] > right[1] ? left[1] : right[1];
            int sum = left[0] + right[0];
            now[1] = max > sum ? max : sum;
            now[0] = 0;
        }
        delete[] left;
        delete[] right;
        // cout << "node:" << node->val << endl;
        // cout << "now[0]: " << now[0] << ", now[1]: " << now[1] << endl;
        return now;
    }
};
