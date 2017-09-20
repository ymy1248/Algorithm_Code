class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        vector<int> node;
        vector<vector<int>> graph(wordList.size(), node);
        int begin = wordList.size() - 1;
        int end = -1;
        
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord) {
                end = i;
            }
            for (int j = i + 1; j < wordList.size(); ++j) {
                int count = 0;
                for (int k = 0; k < beginWord.size(); ++k) {
                    if (wordList[i][k] != wordList[j][k]) {
                        if (++count > 1) {
                            break;
                        }
                    }
                }
                if (count == 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        if (end == -1) {
            return 0;
        }
        
        
        queue<int*> que;
        int* beginNode = new int[2]{begin, 1};
        que.push(beginNode);
        bool* table = new bool[wordList.size()]();
        table[begin] = true;
        
        while (!que.empty()) {
            int* nodeDist = que.front();
            int node = nodeDist[0];
            int dist = nodeDist[1];
            delete [] nodeDist;
            // cout << "node: " << node << ", dist:" << dist << endl;
            que.pop();
            // cout << "q size: " << que.size() << endl;
            
            for (int i = 0; i < graph[node].size(); ++i) {
                if (!table[graph[node][i]]) {
                    if (graph[node][i] == end) {
                        return dist + 1;
                    }
                    int *nextDist = new int[2]{graph[node][i], dist + 1};
                    que.push(nextDist);
                    table[graph[node][i]] = true;
                }
            }
        }
        return 0;
    }
};