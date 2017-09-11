package ymy1248.datastructure;

public class BST <K extends Comparable<K>, V>{
    public BSTNode<K, V> root;

    public BST(){
    }
    
    public void insert(K key, V val) {
        if (root == null) {
            root = new BSTNode<>(key, val);
        } else {
            insert(root, key, val);
        }
    }

    private void insert(BSTNode<K, V> node, K key, V val) {
        while (node != null) {
            if (key.compareTo(node.key) < 0) {
                if (node.left == null) {
                    node.left = new BSTNode<>(key, val);
                    return;
                }
                node = node.left;
            } else if (key.compareTo(node.key) > 0) {
                if (node.right == null) {
                    node.right = new BSTNode<>(key, val);
                    return;
                }
                node = node.right;
            } else {
                node.val = val;
                return;
            }
       }
       node = new BSTNode<>(key, val);
    }

    //public boolean delete(K key) {
    //    // TODO delete
    //}

    public V get(K key) {
        if (root == null) {
            return null;
        }
        return get(root, key);
    }

    private V get(BSTNode<K, V> node, K key) {
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

}
