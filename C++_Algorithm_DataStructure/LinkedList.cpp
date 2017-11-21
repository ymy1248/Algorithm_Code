template <typename V>
LinkedList<V>& LinkedList<V>::add(V val) {
    _last->next = new Node(val);
    _last = _last->next;
    return *this;
}    

template <typename V>
V LinkedList<V>::del() {
    if (empty()) {
        return NULL;
    }

    Node *p = _dummy;
    while (p->next != _last) {
        p = p->next;
    }
    V reg = p->next->val;
    delete p->next;
    p->next = NULL;
    _last = p;
    return reg;
}

template <typename V>
void LinkedList<V>::del(V val) {
    Node *p = _dummy->next;
    Node *last = _dummy;

    while (p != NULL) {
        if (p->val == val) {
            last->next = p->next;
            delete p;
            p = last->next;
            if (p == NULL) {
                return;
            }
        }
        p = p->next;
        last = last->next;
    }
}

template <typename V>
bool LinkedList<V>::empty() const {
    if (_dummy == _last) {
        return true;
    } else {
        return false;
    }
}

template <typename V>
bool LinkedList<V>::contains(V val) {
    Node *p = _dummy->next;
    while (p != NULL) {
        if (p->val == val) {
            return true;
        }
        p = p->next;
    }
    return false;
}

template <typename V>
void LinkedList<V>::clear(){
    Node *p = _dummy->next;
    while (p != _last) {
        Node *next = p->next;
        delete p;
        p = next;
    }
    delete _last;
    _last = _dummy;
}

template <typename V>
void LinkedList<V>::show() const {
    #if DEBUG
    #endif
    cout << "[ ";
    if (!empty()) {
        Node *p = _dummy->next;
        while (p->next != NULL) {
            cout << p->val << " -> ";
            p = p->next;
        }
        cout << p->val;
    }
    cout << " ]\n";
}

template <typename V>
LinkedList<V>::~LinkedList() {
    clear();
    delete _dummy;
}

template <typename V>
ostream & operator<<(ostream &os, LinkedList<V> &l) {
    os << "[ ";
    if (!l.empty()) {
        l._last = l._dummy->next;
        while (l._last->next != NULL) {
            cout << l._last->val << " -> ";
            l._last = l._last->next;
        }
        cout << l._last->val;
    }
    os << " ]\n";
    return os;
}
