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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            vector<TreeNode*> a;
            return a;
        }
        vector<TreeNode*>* trees = subTrees(1, n);
        // cout << "size: " << trees.size() << endl;
        return *trees;
    }
    
    vector<TreeNode*>* subTrees(int lo, int hi) {
        // cout << "lo: " << lo << ", hi: " << hi << endl;
        vector<TreeNode*>* trees = new vector<TreeNode*>;
        if (hi == lo) {
            trees->push_back(new TreeNode(hi));
            return trees;
        }
        
        vector<TreeNode*> rightTree = *subTrees(lo + 1, hi);
        for (int i = 0; i < rightTree.size(); i++) {
            TreeNode* root = new TreeNode(lo);
            root->right = rightTree[i];
            trees->push_back(root);
        }
        for (int i = lo + 1; i < hi; i++) {
            vector<TreeNode*> left = *subTrees(lo, i - 1);
            vector<TreeNode*> right = *subTrees(i + 1, hi);
            for (int j = 0; j < right.size(); j++) {
                for (int k = 0; k < left.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->right = right[j];
                    root->left = left[k];
                    trees->push_back(root);
                }
            }
        }
        vector<TreeNode*> leftTree = *subTrees(lo, hi - 1);
        for(int i = 0; i < leftTree.size(); i++) {
            TreeNode* root = new TreeNode(hi);
            root->left = leftTree[i];
            trees->push_back(root);
        }
        return trees;
    }
};
