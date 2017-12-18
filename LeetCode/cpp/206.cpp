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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        stack<ListNode*> _stack;
        ListNode* p = head;
        ListNode* ans = head;
        while (p->next != NULL) {
            _stack.push(p);
            p = p->next;
        }
        _stack.push(p);
        ans = p;
        while (!_stack.empty()) {
            p->next = _stack.top();
            _stack.pop();
            p = p->next;
        }
        head->next = NULL;
        return ans;
    }
};
