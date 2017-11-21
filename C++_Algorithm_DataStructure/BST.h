#include <iostream>

using namespace std;

template <typename K, typename V>
class BST;

template <typename K, typename V>
class BST {
public:
    void insert(K &key, V &val);
    void del(const K &key);
    bool search(const K &key);

private:
    struct Node {
        Node *left;
        Node *right;
        K key;
        V val;
        Node(K key, V val):
            key(key),
            val(val){};
    };
    Node *root;
    Node* delmin(Node *&node);
    void insert(Node *&node, K &key, V &val);
};

template <typename K, typename V>
void BST<K, V>::insert(K &key, V &val) {
    insert(root, key, val);
}

template <typename K, typename V>
void BST<K, V>::insert(Node<K, V> *&node, K &key, V &val) {
    if (node == NULL) {
        node = new Node<K, V>(key, val);
    } else if (node->key > key) {
        insert(node->left, key, val);
    } else {
        insert(node->right, key, val);
    }
}


template <typename K, typename V>
Node<K, V>* BST<K, V>::delmin(Node<K, V> *&node) {
     
}
template <typename K, typename V>
void BST<K, V>::del(const K &key){

}
