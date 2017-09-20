/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        layer(root);
    }
    
    void layer(TreeLinkNode *head) {
        if (head->left == NULL) {
            return;
        }
        TreeLinkNode *next = head->left;
        TreeLinkNode a = TreeLinkNode(0);
        TreeLinkNode *last = &a;
        while (head != NULL) {
            head->left->next = head->right;
            last->next = head->left;
            last = head->right;
            head = head->next;
        }
        layer(next);
    }
};