#ifndef BST_HPP_
#define BST_HPP_

#include <iostream>
using namespace std;

namespace ymy1248 {
template <typename K, typename V>
class BST {
    struct Node {
        K key;
        V val;
        Node* left; Node* right;
        Node(): left(nullptr), right(nullptr){};
        Node(K _key, V _val): 
            key(_key), val(_val), left(nullptr), right(nullptr){};
    };
    void add(Node*&, const K&, const V&);
    Node* find(Node*, const K&) const;
    bool del(Node*&, const K&);

    Node* _dummy;
    const char* TAG = "BST: ";
    Node* min(Node*) const;

public:
    BST(): _dummy(new Node()){};
    BST& add(const K&, const V&);
    BST& del(const K&) throw(string);
    V get(const K&) const;
    bool empty() const;
    bool contains(const K&) const;
};

#include "BST.cpp"
};
#endif
