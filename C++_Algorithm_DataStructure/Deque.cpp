#include "Deque.hpp"

using namespace ymy1248;

template <typename T>
Deque<T>::Deque() {
    _dummy = new Node();
    _dummy->next = _dummy;
    _dummy->before = _dummy;
}

template <typename T>
void Deque<T>::push_back(const T& data) {
    ++_size;
    Node* node = new Node(data);
    _dummy->before->next = node;
    node->before = _dummy->before;
    node->next = _dummy;
    _dummy->before = node;
}

template <typename T>
void Deque<T>::push_front(const T& data) {
    ++_size;
    Node* node = new Node(data);
    _dummy->next->before = node;
    node->before = _dummy;
    node->next = _dummy->next;
    _dummy->next = node;
}

template <typename T>
T Deque<T>::pop_back() {
    if (empty()) {
        // TODO throw
    }
    --_size;
    Node* node = _dummy->before;
    node->before->next = _dummy;
    _dummy->before = node->before;
    T data = node->data;
    delete node;
    return data;
}

template <typename T>
T Deque<T>::pop_front() {
    if (empty()) {
        // TODO throw exception
    }
    --_size;
    Node* node = _dummy->next;
    node->next->before = _dummy;
    _dummy->next = node->next;
    T data = node->data;
    delete node;
    return data;
}

template <typename T>
T Deque<T>::top() {
    if (empty()) {
        // TODO empty exception
    }
    return _dummy->before->data;
}

template <typename T>
T Deque<T>::last() {
    if (empty()) {
        // TODO empty exception
    }
    return _dummy->next->data;
}

template <typename T>
bool Deque<T>::empty() {
    return _size == 0;
}

template <typename T>
size_t Deque<T>::size() {
    return _size;
}

template <typename T>
Deque<T>::~Deque() {
    Node* p = _dummy->next;
    while (p != _dummy) {
        Node* reg = p->next;
        delete p;
        p = reg;
    }
    delete _dummy;
}

template <typename V>
ostream& operator<<(ostream& os, const Deque<V>& q) {
    typename Deque<V>::Node* node = q._dummy->next;
    os << "[ ";
    while (node != q._dummy->before) {
        os << node->data << ", ";
        node = node->next;
    }
    os << node->data << "]\n";
    return os;
}
