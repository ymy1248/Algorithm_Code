class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> sub;
        vector<vector<char>> dp(s.size(), vector<char>(s.size(), -1));
        for (size_t i = 0; i < s.size(); ++i) {
            dp[i][i] = 1;
        }
        backtrack(ans, sub, s, -1, dp);
        return ans;
    }
private:
    void backtrack(vector<vector<string>> &ans, vector<string> &sub, string &s, int end, vector<vector<char>> &dp) {
        if (end == s.size() - 1) {
            ans.push_back(sub);
        } else {
            for (size_t i = end + 1; i < s.size(); ++i) {
                if (isP(s, dp, end + 1, i)) {
                    sub.push_back(s.substr(end + 1, i - end));
                    backtrack(ans, sub, s, i, dp);
                    sub.pop_back();
                }
            }
        }
    }
    
    char isP(string &s, vector<vector<char>> &dp, int lo, int hi) {
        if (lo >= hi) {
            return 1;
        } else if (dp[lo][hi] != -1) {
            return dp[lo][hi];
        } else {
            if (s[lo] == s[hi] && isP(s, dp, lo + 1, hi - 1)) {
                dp[lo][hi] = 1;
                return 1;
            } else {
                dp[lo][hi] = 0;
                return 0;
            }
        }
    }
};
