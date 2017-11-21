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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> pq;
        ListNode dummy(0);
        ListNode *p = &dummy;
        for(auto l: lists) {
            if (l != NULL) {
                pq.push(pair<int, ListNode*>(-l->val, l));
            }
        }        
        while (!pq.empty()) {
            pair<int, ListNode*> node = pq.top();
            ListNode* l = node.second;
            p->next = l;
            p = p->next;
            pq.pop();
            if (l->next != NULL) {
                pq.push(pair<int, ListNode*>(-l->next->val, l->next));
            }
        }
        return dummy.next;
    }
};
