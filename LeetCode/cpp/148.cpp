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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // for (ListNode* i = head; i != NULL; i = i->next) {
        //     cout << i->val << " ";
        // }
        // cout << endl;
        ListNode* p = head, * half = head;
        while (p->next != NULL && p->next->next != NULL) {
            p = p->next->next;
            half = half->next;
        }
        ListNode* second = half->next;
        half->next = NULL;
        head = sortList(head);
        second = sortList(second);
        return merge(head, second);
    }
    
    ListNode* merge(ListNode* first, ListNode* second) {
        ListNode dummy(0);
        ListNode *p = &dummy;
        while (first != NULL && second != NULL) {
            if (first->val > second->val) {
                p->next = second;
                second = second->next;
            } else {
                p->next = first;
                first = first->next;
            }
            p = p->next;
        }
        if (first == NULL) {
            while (second != NULL) {
                p->next = second;
                second = second->next;
                p = p->next;
            }
        } else if (second == NULL) {
            while (first != NULL) {
                p->next = first;
                first = first->next;
                p = p->next;
            }
        }
        return dummy.next;
    }
};
