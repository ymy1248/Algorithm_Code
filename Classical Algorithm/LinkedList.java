package ymy1248.datastructure;

public class LinkedList<V> {

    private class Node {
        public V val;
        public Node next;

        public Node(V val) {
            this.val = val;
        }
    }

    public int size;
    private Node dummy;

    public LinkedList() {
        this.dummy = new Node(null);
        this.size = 0;
    }
    
    public void add(V val) {
        Node p = dummy;

        while (p.next != null) {
            p = p.next;
        }
        p.next = new Node(val);
        size++;
    }

    public V delete() {
        if (size == 0) {
            return null;
        }

        Node p = dummy;

        while (p.next.next != null) {
            p = p.next;
        }

        V val = p.next.val;
        p.next = null;
        size--;
        return val;
    }

    public boolean isEmpty() {
        return size == 0;
    }
}
