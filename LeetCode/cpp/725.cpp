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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* p = root;
        int n = 0;
        while (p != NULL) {
            ++n;
            p = p->next;
        }
        int each = n / k;
        int one = n % k;
        // cout << "each: " << each << ", one: " << one << endl;
        vector<ListNode*> ans;
        p = root;
        for (int i = 1; i <= k; ++i) {
            ListNode* l;
            if (p != NULL) {
                l = p;
                for (int j = 1; j < each; ++j) {
                    p = p->next;
                    // cout << p->val << endl;
                }
                if (i <= one && each != 0) {
                    p = p->next;
                }
                if (p != NULL) {
                    ListNode* reg = p->next;
                    p->next = NULL;
                    p = reg;
                }
            } else {
                l = NULL;
            }
            ans.push_back(l);
        }
        return ans;
    }
};
