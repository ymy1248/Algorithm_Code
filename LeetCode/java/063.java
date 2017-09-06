class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int[][] grid = obstacleGrid;
        int[][] dp = new int[grid.length][grid[0].length];
        if(grid[0][0] == 0){
            dp[0][0] = 1;
        }
        
        for (int i = 1; i < grid[0].length; i++) {
            if (grid[0][i] != 1) {
                dp[0][i] = dp[0][i-1];
            } else {
                break;
            }
        }
        
        for (int i = 1; i < grid.length; i++) {
            if(grid[i][0] != 1) {
                dp[i][0] = dp[i-1][0];
            } else {
                break;
            }
        }
        
        for (int i = 1; i < grid.length; i++) {
            for (int j = 1; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    continue;
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp[dp.length - 1][dp[0].length - 1];
    }
}
