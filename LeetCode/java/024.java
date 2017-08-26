/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null){
            return head;
        }
        int reg;
        ListNode second = head.next;
        ListNode first = head;
        
        while(first.next != null){
            reg = second.val;
            second.val = first.val;
            first.val = reg;
            if(second.next != null){
                first = first.next.next;
                second = second.next.next;
            } else{
                break;
            }
        }
        return head;
    }
}

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode before = dummy;
        ListNode first = head;
        ListNode second = head.next;
        while(true){
            before.next = second;
            first.next = second.next;
            second.next = first;
            if(first.next != null && first.next.next != null){
                before = first;
                second = first.next.next;
                first = first.next;
            } else{
                return dummy.next;
            }
        }
    }
}
