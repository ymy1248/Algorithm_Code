class Trie {
public:
    struct Node {
        bool isEnd;
        vector<Node*> next;
        Node(): next(vector<Node*>(26, nullptr)), isEnd(false){};
    };
    Node* root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* p = root;
        for (int i = 0; i < word.size(); ++i) {
            if (p->next[word[i] - 'a'] == nullptr) {
                // cout << word[i];
                p->next[word[i] - 'a'] = new Node();
            }
            p = p->next[word[i] - 'a'];
        }
        p->isEnd = true;
        // cout << endl;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* p = root;
        for (int i = 0; i < word.size(); ++i) {
            // cout << word[i];
            if (p->next[word[i] - 'a'] == nullptr) {
                // cout << endl;
                return false;
            }
            p = p->next[word[i] - 'a'];
        }
        // cout << endl;
        if (p->isEnd) {
            return true;
        } else {
            return false;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* p = root;
        for (int i = 0; i < prefix.size(); ++i) {
            if (p->next[prefix[i] - 'a'] == nullptr) {
                return false;
            }
            p = p->next[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
