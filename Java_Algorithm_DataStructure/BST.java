package ymy1248.datastructure;

public class BST <K extends Comparable<K>, V>{
    private class BSTNode {
        public K key;
        public V val;
        public BSTNode left;
        public BSTNode right;

        public BSTNode(K key, V val) {
            this.key = key;
            this.val = val;
        }
    }

    public BSTNode root;

    public BST(){
    }

    public boolean contains(K key) {
        return get(root, key) != null;
    }
    
    public void insert(K key, V val) {
        if (root == null) {
            root = new BSTNode(key, val);
        } else {
            insert(root, key, val);
        }
    }

    private void insert(BSTNode node, K key, V val) {
        while (node != null) {
            if (key.compareTo(node.key) < 0) {
                if (node.left == null) {
                    node.left = new BSTNode(key, val);
                    return;
                }
                node = node.left;
            } else if (key.compareTo(node.key) > 0) {
                if (node.right == null) {
                    node.right = new BSTNode(key, val);
                    return;
                }
                node = node.right;
            } else {
                node.val = val;
                return;
            }
       }
       node = new BSTNode(key, val);
    }

    public boolean delete(K key) {
        if (contains(key)) {
            root = delete(root, key);
            return true;
        } else {
            return false;
        }
    }

    private BSTNode delete(BSTNode node, K key) {
        if (node == null) {
            return null;
        }
        if (key.compareTo(node.key) < 0) {
            node.left = delete(node.left, key);
        } else if (key.compareTo(node.key) > 0) {
            node.right = delete(node.right, key);
        } else {
            if (node.left == null && node.right == null) {
                return null;
            } else if (node.left != null && node.right != null) {
                BSTNode minNode =  min(node.right);
                node.right = delete(node.right, minNode.key);
                minNode.left = node.left;
                minNode.right = node.right;
                return minNode;
            } else {
                return node.left == null ? node.right : node.left;
            }
        }
        return node;
    }

    public V min() {
        return min(root).val;
    }

    private BSTNode min(BSTNode node) {
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }


    public V get(K key) {
        if (root == null) {
            return null;
        }
        return get(root, key);
    }

    private V get(BSTNode node, K key) {
        if (node == null) {
            return null;
        }

        if (key.compareTo(node.key) < 0) {
            return get(node.left, key);
        } else if (key.compareTo(node.key) > 0) {
            return get(node.right, key);
        } else {
            return node.val;
        }
    }

    @Override
    public String toString() {
        return toString(0);
    }

    public String toString(int mode) {
        StringBuilder sb = new StringBuilder();
        toString(this.root, mode, sb);
        return sb.toString();
    }

    private void toString(BSTNode node, int mode, StringBuilder sb) {
        if (node == null){
            return;
        }
        if (mode == 0) {
            toString(node.left, mode, sb);
            sb.append(node.key + " ");
            toString(node.right, mode, sb);
        } else if (mode < 0) {
            System.out.print(node.key + " ");
            toString(node.left, mode, sb);
            toString(node.right, mode, sb);
        } else {
            toString(node.left, mode, sb);
            toString(node.right, mode, sb);
            sb.append(node.key + " ");
        }
    }
}
