package ymy1248.datastructure;

public class BST <K extends Comparable<K>, V>{
    public BSTNode<K, V> root;

    public BST(){
    }

    public boolean contains(K key) {
        return get(root, key) != null;
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

    public boolean delete(K key) {
        if (contains(key)) {
            root = delete(root, key);
            return true;
        } else {
            return false;
        }
    }

    private BSTNode<K, V> delete(BSTNode<K, V> node, K key) {
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
                BSTNode<K, V> minNode =  min(node.right);
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

    private BSTNode<K, V> min(BSTNode<K, V> node) {
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
