class Solution {
public:
    vector<int> getRow(int k) {
        vector<int> last(k + 1, 0);
        vector<int> now(k + 1, 0);
        for (int i = 0; i < k + 1; ++i) {
            last = now;
            now[0] = 1;
            now[now.size() - 1] = 1;
            for (int j = 1; j < k; ++j) {
                now[j] = last[j - 1] + last[j];
            }
        }
        return now;
    }
};
