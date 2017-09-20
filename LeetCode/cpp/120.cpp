class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int* dp = new int[triangle.size()];
        dp[0] = triangle[0][0];
        
        for (int i = 1; i < triangle.size(); i++) {
            int before = dp[0];
            dp[0] = dp[0] + triangle[i][0];
            for (int j = 1; j < triangle[i].size() - 1; j++) {
                int reg = dp[j];
                dp[j] = min(before, dp[j]) + triangle[i][j];
                before = reg;
            }
            dp[triangle[i].size() - 1] = before + triangle[i][triangle[i].size() - 1];
        }
        
        int ans = dp[0];
        for (int i = 1; i < triangle.size(); i++) {
            ans = min(dp[i], ans);
        }
        return ans;
    }
    
    int min (int a, int b) {
        return a < b ? a : b;
    }
};