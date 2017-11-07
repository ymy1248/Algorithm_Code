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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast != NULL) {
            fast = fast->next;
            if (fast == NULL) {
                break;
            }
            fast = fast->next;
            slow = slow->next;
            if (fast == slow) {
                break;
            }
        }
        if (fast == NULL) {
            return NULL;
        } else {
            fast = head;
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return fast;
    }
};
