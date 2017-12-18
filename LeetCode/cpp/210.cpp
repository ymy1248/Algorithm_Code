class Solution {
public:
    vector<int> findOrder(int n, vector<pair<int, int>>& prerequisites) {
        vector<bool> visted(n, false), path(n, false);
        vector<vector<bool>> graph(n, visted);
        vector<int> indegree (n, 0);

        for (auto p: prerequisites) {
            graph[p.second][p.first] = true; 
            indegree[p.first]++;
        }

        for (int i = 0; i < n; ++i) {
            if (!visted[i] && dfsCyc(graph, visted, path, i)) {
                return vector<int>();
            }
        }

        vector<int> ans;
        visted = vector<bool>(n, false);

        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                topSort(graph, i, ans, visted);
            }
        }
        return ans;
    }

    void topSort(vector<vector<bool>>& graph, int node, vector<int>& ans, vector<bool>& visted) {
        if (visted[node]) {
            return;
        }
        visted[node] = true;
        for (size_t i = 0; i < visted.size(); ++i) {
            if (graph[node][i]) {
                topSort(graph, i, ans, visted);
            }
        }
        ans.insert(ans.begin(), node);
    }

    bool dfsCyc(vector<vector<bool>>& graph, vector<bool>& visted, vector<bool>& path, int node) {
        if (visted[node]) {
            return false;
        }
        path[node] = visted[node] = true;
        for (size_t i = 0; i < graph.size(); ++i) {
            if (graph[node][i] && (path[i] == true || dfsCyc(graph, visted, path, i))) {
                return true;
            }
        }
        return path[node] = false;
    }
};

