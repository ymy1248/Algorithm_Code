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
        if (head == null || head.next == null) {
            return head;
        }
        if (head.val == head.next.val){
            int lastVal = head.val;
            for (ListNode p = head.next;; p = p.next) {
                if (p == null) {
                    return null;
                }
                if (p.val != lastVal && (p.next == null || p.next.val != p.val)) {
                    head = p;
                    break;
                } else {
                    lastVal = p.val;
                }
            }
        }
        
        ListNode node = head;
        int lastVal = head.val;
        for (ListNode p = head.next; p != null; p = p.next) {
            if (p.val != lastVal && (p.next == null || p.next.val != p.val)) {
                    node.next = p;
                    node = node.next;
            } 
            lastVal = p.val;
        }
        node.next = null;
        return head;
    }
}
