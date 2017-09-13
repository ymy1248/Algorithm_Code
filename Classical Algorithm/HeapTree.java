package ymy1248.datastructure;

public class HeapTree<K extends Comparable<K>> {
    private class Node {
        public K key;
        public Node parent;
        public Node left;
        public Node right;

        public Node(K key) {
            this.key = key;
        }
    }

    private Node root;
    private int size;
    private final int mode;

    public HeapTree(boolean isMax) {
        if (isMax) {
            this.mode = 1;
        } else {
            this.mode = -1;
        }
    }

    public void insert(K key) {
        size++;
        if (root == null) {
            this.root = new Node(key);
        } else {
            Node p = getEndParent();
            if (p.left == null) {
                p.left = new Node(key);
                p.left.parent = p;
                p = p.left;
            } else {
                p.right = new Node(key);
                p.right.parent = p;
                p = p.right;
            }
            upHeapify(p); 
        }
    }

    private void upHeapify(Node node) {
        int comp = node.key.compareTo(node.parent.key) * this.mode;
        while (node.parent != null &&  comp > 0) {
            swap(node, node.parent);
        }
    }

    private void downHeapify(Node node) {
        Node reg = null;
        while (node.left != null || node.right != null) {
            reg = swapChildren(node);
            if (node == reg) {
                break;
            } else {
                node = reg;
            }
        }
    }

    private void swap(Node a, Node b) {
        K reg = a.key;
        b.key = a.key;
        a.key = reg;
    }

    private Node swapChildren(Node node) {
        Node p = node;
        
        if (node.left != null && node.right != null) {
            int comp = node.right.key.compareTo(node.left.key) * this.mode;
            if (comp > 0) {
                p = node.right;
            }
        } else if (node.left != null && node.right == null) {
            p = node.right;
        } else {
            p = node.left;
        }

        int comp = node.key.compareTo(p.key) * this.mode;
        if(comp < 0) {
            swap(node, p);
            return p;
        } else {
            return node;
        }
    }

    private Node getEndParent() {
        Node p = root;
        char[] posChar = Integer.toString(size, 2).toCharArray();
        for (int i = 1; i < posChar.length - 1; i++) {
            if (posChar[i] == '0') {
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return p;
    }
        
    public K getM() {
        Node p = getEndParent();
        K returnK;
        if (p.left != null) {
            returnK = root.key;
            swap(p.left, root);
            p.left = null;
        } else {
            returnK = root.key;
            swap(p.right, root);
            p.right = null;
        }
        downHeapify(root);
        return returnK;
    }
}
