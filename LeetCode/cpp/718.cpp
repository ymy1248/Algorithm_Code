class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int max = 0;
        int dp[A.size() + 1][B.size() + 1];
        for (int i = 0; i < A.size() + 1; ++i) {
            for (int j = 0; j < B.size() + 1; ++j) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                if (A[i] == B[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = 0;
                }
                // cout << i + 1 << ", " << j + 1 << ":" << dp[i + 1][j + 1] << endl;
                max = dp[i + 1][j + 1] > max ? dp[i + 1][j + 1] : max;
            }
        }
        return max;
    }
};
