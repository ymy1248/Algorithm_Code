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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode *mNode, *beforeM = &dummy;
        ListNode *last = &dummy, *now = dummy.next;
        int count = 1;
        
        while (now->next != NULL && count < n ) {
            if (count > m  && count < n) {
                ListNode* reg = now->next;
                now->next = last;
                last = now;
                now = reg;
            } else if (count == m) {
                mNode = now;
                last = now;
                now = now->next;
            } else if (count == m - 1) {
                beforeM = now;
                last = now;
                now = now->next;
            } else {
                last = now;
                now = now->next;
            }
            count++;
        }
        // cout << "m val: " << mNode->val << endl;
        // cout << "now val: " << now->val << endl;
        // cout << "beforeM val: " << beforeM->val << endl;
        // cout << "last val: " << last->val << endl;
        mNode->next = now->next;
        now->next = last;
        beforeM->next = now;
        
        return dummy.next;
    }
};
