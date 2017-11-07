class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') {
            return 0;
        }
        if (s.size() == 1) {
            return 1;
        }
        int *dp = new int [s.size()];
        dp[0] = 1;
        if ((s[0] == '1' && s[1] != '0') || (s[0] == '2' && s[1] <= '6' && s[1] != '0')) {
            dp[1] = 2;
        } else {
            dp[1] = 1;
        }
        if (s[1] == '0' && (s[0] !='1' && s[0] != '2')) {
            return 0;
        }
        for (size_t i = 2; i < s.size(); ++i) {
            if (s[i] == '0' && (s[i - 1] !='1' && s[i - 1] != '2')) {
                return 0;
            } else if (s[i] == '0') {
                dp[i] = dp[i - 2];
            } else if ((s[i - 1] == '1' && s[i] != '0') || (s[i - 1] == '2' && s[i] <= '6')) {
                dp[i] = dp[i - 1] + dp[i - 2];
            } 
            else {
                dp[i] = dp[i - 1];
            }
        }
        // for (size_t i = 0; i < s.size(); ++i) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        return dp[s.size() - 1];
    }
};
