class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<double> a(K + 1, -2);
        vector<vector<double>> b(N + 1, a);
        vector<vector<vector<double>>> dp(N + 1, b);
        double move = 1;
        for (int i = 0; i < K; ++i) {
            move *= 8;
        }
        double num = foo(dp, r, c, K, N);
        return num/move;
    }

private:
    double foo(vector<vector<vector<double>>> &dp, int r, int c, int K, int N) {
        if (r < 0 || r >= N || c < 0 || c >= N) {
            return 0;
        }
        if (K == 0) {
            return 1.0;
        }
        if (dp[r][c][K] > -1) {
            return dp[r][c][K];
        }
        dp[r][c][K] = foo(dp, r + 2, c + 1, K - 1, N) + 
                      foo(dp, r + 2, c - 1, K - 1, N) + 
                      foo(dp, r - 2, c + 1, K - 1, N) + 
                      foo(dp, r - 2, c - 1, K - 1, N) + 
                      foo(dp, r + 1, c + 2, K - 1, N) + 
                      foo(dp, r + 1, c - 2, K - 1, N) + 
                      foo(dp, r - 1, c + 2, K - 1, N) + 
                      foo(dp, r - 1, c - 2, K - 1, N);
        return dp[r][c][K];
            
    }
};
