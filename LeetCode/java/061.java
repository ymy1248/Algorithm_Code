/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (k == 0 || head == null || head.next == null) {
            return head;
        }
        ListNode node = null;
        ListNode p = head;
        int count = 0;
        
        while (true) {
            p = p.next;
            count++;
            if (count > k) {
                node = node.next;
            } else if (count == k){
                node = head;
            }
            if (p.next == null && count < k) {
                // System.out.println(count);
                p = head;
                node = null;
                k %= count + 1;
                if (k == 0) {
                    return head;
                }
                count = 0;
            } else if (p.next == null && count >= k) {
                break;
            }
        }
        
        p.next = head;
        head = node.next;
        node.next = null;
        
        return head;
    }
}
