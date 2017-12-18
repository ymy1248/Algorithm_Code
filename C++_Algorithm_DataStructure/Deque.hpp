#ifndef DEQUE_H_
#define DEQUE_H_

#include "consts.h"

namespace ymy1248{ 
template <typename T>
class Deque {
private:
    struct Node {
        Node* next;
        Node* before;
        T data;
        Node(): next(nullptr), before(nullptr){};
        Node(T _data): next(nullptr), before(nullptr), data(_data){};
    };
    Node* _dummy;
    size_t _size;

public:
    Deque();
    void push_back(const T&);
    void push_front(const T&);
    bool empty();
    size_t size();
    T pop_back();
    T pop_front();
    T top();
    T last();
    virtual ~Deque();
    template <typename V>
    friend ostream& operator<<(ostream&, const Deque<V>&);
};

#include "Deque.cpp"
}


#endif
