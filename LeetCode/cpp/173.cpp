/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        inorder(arr, root);
        index = 0;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index < arr.size();
    }

    /** @return the next smallest number */
    int next() {
        return arr[index++];
    }
private:
    vector<int> arr;
    int index;
    void inorder(vector<int>& arr, TreeNode* node) {
        if (node == NULL) {
            return;
        }
        inorder(arr, node->left);
        arr.push_back(node->val);
        inorder(arr, node->right);
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
