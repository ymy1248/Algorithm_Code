/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* p = head;
        vector<ListNode*> list;
        
        while (p != NULL) {
            list.push_back(p);
            p = p->next;
        }
        // cout << "it's ok" << endl;
        TreeNode* root = build(list, 0, list.size() - 1);
        return root;
    }
    
    TreeNode* build(vector<ListNode*>& list, int lo, int hi) {
        if (hi < lo) {
            return NULL;
        }
        int mid = (lo + hi) / 2;
        // cout << "it's ok, lo:" << lo << ", hi:" << hi << ", mid:" << mid <<endl;
        ListNode* p = list[mid];
        TreeNode* node = new TreeNode(p->val);
        node->left = build(list, lo, mid - 1);
        node->right = build(list, mid + 1, hi);
        return node;
    }
};
