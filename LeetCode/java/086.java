/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode dummy1 = new ListNode(0), dummy2 = new ListNode(0);
        ListNode q1 = dummy1, q2 = dummy2;
        ListNode p = head;
        
        while (p != null) {
            if (p.val < x) {
                q1.next = p;
                q1 = q1.next;
            } else {
                q2.next = p;
                q2 = q2.next;
            }
            p = p.next;
        }
        
        q2.next = null;
        q1.next = dummy2.next;
        return dummy1.next;
    }
}
