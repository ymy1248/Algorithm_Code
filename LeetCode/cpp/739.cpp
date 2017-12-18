class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size(), 0);
        vector<int> waits(101, INT_MAX);
        
        for (int i = t.size() - 1; i >= 0; --i) {
            if (waits[t[i]] > i) {
                waits[t[i]] = i;
            }
            int nextT = INT_MAX;
            for (int j = t[i] + 1; j < 101; ++j) {
                if (waits[j] != INT_MAX) {
                    nextT = min(waits[j] - i, nextT);
                }
            }
            if (nextT != INT_MAX) {
                ans[i] = nextT;
            } else {
                ans[i] = 0;
            }
        }
        return ans;
    }
};
