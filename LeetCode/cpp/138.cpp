/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p, *dummy, *it;
        dummy = new RandomListNode(0);
        unordered_map<RandomListNode *, RandomListNode *> map;
        for (p = head, it = dummy; p != NULL; p = p->next, it = it->next) {
            it->next = new RandomListNode(p->label);
            map[p] = it->next;
        }
        
        for (p = head, it = dummy; p != NULL; p = p->next, it = it->next) {
            if (p->random == NULL) {
                continue;
            }
            auto iter = map.find(p->random);
            it->next->random = iter->second;
        }
        return dummy->next;
    }
};
