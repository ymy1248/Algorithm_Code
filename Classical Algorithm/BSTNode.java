package ymy1248.datastructure;

public class BSTNode <K extends Comparable<K>, V>{
    public K key;
    public V val;
    public BSTNode<K, V> left;
    public BSTNode<K, V> right;

    public BSTNode(K key, V val) {
        this.key = key;
        this.val = val;
    }
}
