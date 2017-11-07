class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0, b = 0;
        ListNode *pA = headA, *pB = headB;
        while (pA != NULL) {
            a++;
            pA = pA->next;
        }
        while (pB != NULL) {
            b++;
            pB = pB->next;
        }
        pA = headA;
        pB = headB;
        int diff = a - b;
        if (diff > 0) {
            while (diff > 0) {
                pA = pA->next;
                diff--;
            }
        } else {
            diff = -diff;
            while (diff > 0) {
                pB = pB->next;
                diff--;
            }
        }
        
        while (pA != NULL && pB != NULL) {
            if (pA == pB) {
                return pA;
            }
            pA = pA->next;
            pB = pB->next;
        }
        return NULL;
    }
};

