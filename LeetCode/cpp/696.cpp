class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& pos) {
        set<int> lineSet;
        unordered_map<int, int> pos2i;
        vector<int> ans(pos.size(), 0);
        int max = -1;
        for (size_t i = 0; i < pos.size(); ++i) {
            int left = pos[i].first;
            int right = pos[i].first + pos[i].second;
            lineSet.insert(left);
            lineSet.insert(right);
        }
        vector<int> line(lineSet.begin(), lineSet.end());
        for (size_t i = 0; i < line.size(); ++i) {
            cout << line[i] << " ";
            pos2i[line[i]] = i;
        }
        cout << endl;
        
        vector<int> height(pos.size() * 2, 0);
        for (size_t i = 0; i < pos.size(); ++i) {
            int left = pos[i].first;
            int right = pos[i].first + pos[i].second;
            int l = pos2i.find(left)->second;
            int r = pos2i.find(right)->second;
            int h = update(height, l, r, pos[i].second);
            max = max > h ? max : h;
            ans[i] = max;
            cout << "max: " << max << ", h: " << h << endl;
            for (size_t i = 0; i < ans.size(); ++i) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        cout << ans[1] << endl;
        return ans;
    }
    
private:
    int update(vector<int> &height, int l, int r, int len) {
        int h = -1;
        for (int i = l; i < r; ++i) {
            h = h > height[i] ? h : height[i];
        }
        h += len;
        for (int i = l; i < r; ++i) {
            height[i] = h;
        }
        return h;
    }
};
