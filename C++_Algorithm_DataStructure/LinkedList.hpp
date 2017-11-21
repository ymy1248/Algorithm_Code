#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string>
#include "consts.h"

namespace ymy1248{
template <typename V>
class LinkedList {
public:
    LinkedList() : _dummy(new Node(NULL)), _last(_dummy){};
    LinkedList<V> &add(V val);
    V del();
    void del(V val);
    bool empty() const;
    bool contains(V val);
    void clear();
    void show() const;
    virtual ~LinkedList();
    template <typename T>
    friend ostream & operator<<(ostream &os, LinkedList<T> &l);

private:
    struct Node {
        V val;
        Node *next;
        Node(V v): val(v), next(NULL){};
    };
    Node *_dummy, *_last;
};

#include "LinkedList.cpp"
}

#endif
