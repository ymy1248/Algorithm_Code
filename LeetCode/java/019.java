/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head.next == null){
            return null;
        }
        
        ListNode p = head;
        ListNode nNode = null;
        int ith = 0;
        
        while(p.next != null){
            if(++ith == n){
                nNode = head;
            } else if(ith > n){
                nNode = nNode.next;
            }
            p = p.next;
        }
        if(nNode == null){
            head = head.next;
        } else{
            nNode.next = nNode.next.next;
        }
        return head;
    }
}
