class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int lastx = ans;
            ans *= 10;
            ans += x % 10;
            x /= 10;
            if (ans / 10 != lastx) {
                return 0;
            }
        }
        return ans;
    }
};
