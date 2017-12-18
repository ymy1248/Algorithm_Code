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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }
        ListNode* p = head, * p2 = head, * last = NULL, * next = NULL;
        while (p2->next != NULL && p2->next->next != NULL) {
            p2 = p2->next->next;
            next = p->next;
            p->next = last;
            last = p;
            p = next;
        }
        next = p->next;
        p->next = last;
        
        if (p2->next == NULL && p2 != head) {
            p = p->next;
        }
        
        while (next != NULL && p != NULL) {
            if (next->val != p->val) {
                return false;
            }
            next = next->next;
            p = p->next;
        }
        return true;
    }
};
