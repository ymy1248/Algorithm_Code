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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = head;
        ListNode* last = &dummy;
        
        while (p != NULL) {
            if (p->val == val) {
                last->next = p->next;
            } else {
                last = last->next;
            }
            p = p->next;
        }
        return dummy.next;
    }
};
