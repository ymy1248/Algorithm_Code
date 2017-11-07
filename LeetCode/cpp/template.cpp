#include "template.h"

struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> _map;
        UndirectedGraphNode *dummy = new UndirectedGraphNode(0);
        dummy->neighbors.push_back(clone(node, _map));
        return dummy->neighbors[0];
    }

    UndirectedGraphNode * clone(UndirectedGraphNode *node,
            unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &_map) {
        auto it = _map.find(node);
        if (it != _map.end()) {
            return it->second;
        } else {
            UndirectedGraphNode *p = new UndirectedGraphNode(node->label);
            _map[node] = p;
            for (size_t i = 0; i < node->neighbors.size(); --i) {
                UndirectedGraphNode *reg = clone(node->neighbors[i], _map);
                if (reg != NULL) {
                    p->neighbors.push_back(reg);
                }
            }
            return p;
        }
    }
};
