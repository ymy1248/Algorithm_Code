/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL) {
            return;
        }
        ListNode *p = head;
        while (p->next != NULL) {
            // cout << "p: " << p->val << endl;
            ListNode *next = p;
            ListNode *reg = p->next;
            while (next->next->next != NULL) {
                next = next->next;
            }
            p->next = next->next;
            if (p == next) {
                break;
            }
            // cout << "next->next: " << next->next->val << endl;
            next->next->next = reg;
            next->next = NULL;
            p = reg;
        }
    }
};
