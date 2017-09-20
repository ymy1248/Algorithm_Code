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
        if (head == NULL) {
            return;
        }
        TreeLinkNode *next = NULL;
        TreeLinkNode *last = NULL;
        while (head != NULL) {
            if (next == NULL) {
                if (head->left != NULL && head->right == NULL) {
                    next = head->left;
                    last = head->left;
                } else if (head->left == NULL && head->right != NULL) {
                    next = head->right;
                    last = head->right;
                } else if (head->left != NULL && head->right != NULL) {
                    head->left->next = head->right;
                    next = head->left;
                    last = head->right;
                }
            } else {
                if (head->left != NULL) {
                    last->next = head->left;
                    last = last->next;
                }
                if (head->right != NULL) {
                    last->next = head->right;
                    last = last->next;
                }
            }
            head = head->next;
        }
        layer(next);
    }
};