class Solution {
    public boolean canJump(int[] nums) {
        boolean[] dp = new boolean[nums.length];
        dp[0] = true;
        int p = 0;
        for (int i = 0; i < dp.length; i++) {
            if (dp[i] == false) {
                continue;
            }
            if (i + nums[i] > dp.length - 1) {
                return true;
            }
            for (int j = i + nums[i]; j >= i && dp[j] != true; j--) {
                dp[j] = true;
            }
            if (dp[dp.length - 1]) {
                return true;
            }
        }
        // System.out.println(Arrays.toString(dp));
        return dp[dp.length - 1];
    }
}
