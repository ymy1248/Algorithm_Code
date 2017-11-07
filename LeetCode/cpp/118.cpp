class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 0) {
            return ans;
        }
        vector<int> *last = new vector<int>(1, 1);
        ans.push_back(*last);
        for (int i = 2; i <= numRows; ++i) {
            vector<int> *now = new vector<int>(i,0);
            (*now)[0] = 1;
            (*now)[now->size() - 1] = 1;
            for (int i = 1; i < now->size() - 1; ++i) {
                (*now)[i] = (*last)[i - 1] + (*last)[i];
            }
            delete last;
            ans.push_back(*now);
            last = now;
        }
        return ans;
    }
};
