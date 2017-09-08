/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null)
            return head;
        int last = head.val;
        ListNode p = head;
        ListNode lastNode = head;
        
        while(p != null) {
            if (p.val != last) {
                lastNode.next = p;
                last = p.val;
                lastNode = p;
            }
            p = p.next;
        }
        lastNode.next = null;
        return head;
    }
}
