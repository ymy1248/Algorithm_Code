#ifndef BST_HPP_
#define BST_HPP_

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Deque.hpp"
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
    void bstTable(Node*, Node***, int, int, int lo, int hi) const;
    int getMaxKeyLen() const;
    int getMaxKeyLen(Node*) const;
    Node*** bstTable() const;

public:
    BST(): _dummy(new Node()){};
    BST& add(const K&, const V&);
    BST& del(const K&) throw(string);
    V get(const K&) const;
    bool empty() const;
    bool test(const Deque<int>&);
    bool contains(const K&) const;
    unsigned int height() const;
    unsigned int height(Node*, unsigned int) const;
    Deque<Node*> flatBST();
    template <typename A, typename B>
    friend ostream& operator<<(ostream&, const BST<A, B>&);
};

#include "BST.cpp"
};
#endif
