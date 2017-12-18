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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        ListNode* newHead = head;
        for (int i = 0; i < k - 1 && newHead != NULL; ++i) {
            newHead = newHead->next;
        }
        if (newHead == NULL) {
            return head;
        }
        
        while (p != NULL) {
            ListNode* nextK = p;
            for (int i = 0; i < k - 1 && nextK != NULL; ++i) {
                nextK = nextK->next;
            }
            if (nextK == NULL) {
                break;
            }
            ListNode* nextnextK = nextK;
            for (int i = 0; i < k && nextnextK != NULL; ++i) {
                nextnextK = nextnextK->next;
            }
            
            ListNode* reg = p->next;
            if (nextnextK != NULL) {
                p->next = nextnextK;
            } else {
                p->next = nextK->next;
            }
            ListNode* last = p;
            p = reg;
            for (int i = 0; i < k - 1; ++i) {
                reg = p->next;
                p->next = last;
                last = p;
                p = reg;
            }
        }
        return newHead;
    }
};
