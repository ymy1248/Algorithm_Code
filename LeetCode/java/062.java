class Solution {
    public int uniquePaths(int m, int n) {
        if (m < n) {
            int reg = m;
            m = n;
            n = reg;
        }
        int count = 1;
        double ans = 1;
        for (int i = m + n - 2; i > m - 1; i--) {
            ans *= i;
            ans /= count++;
        }
        return (int)ans;
    }
}
