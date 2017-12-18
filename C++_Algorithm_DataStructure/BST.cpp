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
             j< "key: " << key << ", node: " << p->key << endl;
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

template <typename K, typename V>
unsigned int BST<K, V>::height() const {
    return height(_dummy->left, 0);
}

template <typename K, typename V>
unsigned int BST<K, V>::height(Node* node, unsigned int h) const {
    if (node == nullptr) {
        return h;
    }
    return max(height(node->right, h + 1), height(node->left, h + 1));
}

template <typename K, typename V>
typename BST<K, V>::Node*** BST<K, V>::bstTable() const {
    int h = height();
    int level = 1;
    for (int i = 0; i < h; ++i) {
        level *= 2;
    }
    level -= 1;
    cout << "level: " << level << endl;
    Node*** table = new Node**[h];
    for (int i = 0; i < h; ++i) {
        table[i] = new Node*[level];
        for (int j = 0; j < level; ++j) {
            table[i][j] = nullptr;
        }
    }
    bstTable(_dummy->left, table, h, 0, 0, level - 1);
    return table;
}

template <typename K, typename V>
void BST<K, V>::bstTable(Node* node, Node*** table, int height, int cur, int lo, int hi) const {
    if (cur >= height) {
        return;
    }
    int mid = (lo + hi) / 2;
    table[cur][mid] = node;
    if (node == nullptr) {
        bstTable(nullptr, table, height, cur + 1, lo, mid - 1);
        bstTable(nullptr, table, height, cur + 1, mid + 1, hi);
    } else {
        bstTable(node->left, table, height, cur + 1, lo, mid - 1);
        bstTable(node->right, table, height, cur + 1, mid + 1, hi);
    }
}

template <typename K, typename V>
int BST<K, V>::getMaxKeyLen() const {
    return getMaxKeyLen(_dummy->left);
}

template <typename K, typename V>
int BST<K, V>::getMaxKeyLen(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    ostringstream oss;
    oss << node->val;
    string s = oss.str();
    int maxLen = max(getMaxKeyLen(node->left), getMaxKeyLen(node->right));
    maxLen = max(maxLen, int(s.size()));
    return maxLen;
}
    
template <typename K, typename V>
ostream& operator<<(ostream& os, const BST<K, V>& bst) {
    using Node = typename BST<K, V>::Node;
    Node*** table = bst.bstTable();
    int maxLen = bst.getMaxKeyLen();
    int h = bst.height();
    int level = 1;
    for (int i = 0; i < h; ++i) {
        level *= 2;
    }
    level -= 1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < level; ++j) {
            if (table[i][j] == nullptr) {
                cout << setw(maxLen + 1) << " ";
            } else {
                cout << setw(maxLen) << table[i][j]->key;
                cout << " ";
            }
        }
        os << endl;
        for (int j = 0; j < level; ++j) {
            if (table[i][j] == nullptr) {
                cout << setw(maxLen + 1) << " ";
            } else {
                cout << "\e[" << 1 << "D";
                cout << "/";
                cout << setw(maxLen + 1) << "\\";
            }
        }
        os << endl;

    }
    return os; 
}

