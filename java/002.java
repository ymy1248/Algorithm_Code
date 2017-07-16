/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return add(l1, l2, 0);
    }
    
    public ListNode add(ListNode l1, ListNode l2, int one){
        if(l1 == null && l2 == null){
            if(one == 0){
                return null;
            }
            return new ListNode(one);
        }
        if(l1 == null){
            int result = l2.val + one;
            ListNode ans = new ListNode(result%10);
            ans.next = add(l1, l2.next, result/10);
            return ans;
        }
        if(l2 == null){
            int result = l1.val + one;
            ListNode ans = new ListNode(result%10);
            ans.next = add(l1.next, l2, result/10);
            return ans;
        }
        int result = l1.val + l2.val + one;
        ListNode ans = new ListNode(result%10);
        ans.next = add(l1.next, l2.next, result/10);
        return ans;
    }
}
