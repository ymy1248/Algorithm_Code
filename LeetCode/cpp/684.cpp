class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int nodes[2001];
        for (size_t i = 0; i < 2001; ++i) {
            nodes[i] = i;
        }
        for (size_t i = 0; i < edges.size(); ++i) {
            if (connect(nodes, edges[i][0], edges[i][1])) {
                return edges[i];
            }
        }
        return vector<int>{0,0};
    }
    bool connect(int* nodes, int u, int v) {
        while (nodes[u] != u) {
            u = nodes[u];
        }
        while (nodes[v] != v) {
            v = nodes[v];
        }
        if (u == v) {
            return true;
        } else {
            nodes[u] = v;
            return false;
        }
    }
};

