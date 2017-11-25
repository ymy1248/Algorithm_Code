#include "BST.hpp"
using namespace ymy1248;

template <typename K, typename V>
BST<K, V>& BST<K, V>::add(const K& key, const V& val) {
    add(_dummy->left, key, val);
    return *this;
}

template <typename K, typename V>
void BST<K, V>::add(Node*& p, const K& key, const V& val) {
    if (p == nullptr) {
        p = new Node(key, val);
    } else {
        #if DEBUG
        cout << TAG << "add(Node*&, const K&, const V&): "
             << "key: " << key << ", node: " << p->key << endl;
        #endif
        if (key < p->key) {
            add(p->left, key, val);
        } else if (key > p->key) {
            add(p->right, key, val);
        } else {
            p->val = val;
        }
    }
}

template <typename K, typename V>
bool BST<K, V>::empty() const {
    return _dummy->left == nullptr;
}

template <typename K, typename V>
bool BST<K, V>::contains(const K& key) const {
    #if DEBUG
    cout << TAG << "contains(K): key = " << key << endl;
    #endif
    return find(_dummy->left, key) != nullptr;
}

template <typename K, typename V>
typename BST<K,V>::Node* BST<K, V>::find(Node* p, const K& key) const {
    if (p == nullptr) {
        return nullptr;
    }
    #if DEBUG
    cout << TAG << "find(Node*, K&): p->val = " << p->val << endl;
    #endif
    if (key < p->key) {
        return find(p->left, key);
    } else if (key > p->key) {
        return find(p->right, key);
    } else {
        return p;
    }
}

template <typename K, typename V>
BST<K, V>& BST<K, V>::del(const K& key) throw(string) {
    if (empty()) {
        throw "The BST is empty";
    } else {
        del(_dummy->left, key);
    }
    return *this;
}

template <typename K, typename V>
bool BST<K, V>::del(Node*& node, const K& key) {
    if (node == nullptr) {
        return false;
    }
    if (key > node->key) {
        return del(node->right, key);
    } else if (key < node->key) {
        return del(node->left, key);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            node = nullptr;
            delete node;
            return true;
        } else if (node->right == nullptr) {
            node = node->left;
            delete node;
            return true;
        } else {
            Node* p = min(node);
            node->key = p->key;
            node->val = p->val;
            delete p;
            return true;
        }
    }
    return false;
}

template <typename K, typename V>
typename BST<K, V>::Node* BST<K,V>::min(Node* node) const {
    Node* p = node;
    while (p->left != nullptr) {
        p = p->left;
    }
    return p;
}
