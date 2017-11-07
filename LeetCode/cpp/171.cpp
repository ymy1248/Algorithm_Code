class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        int base = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == 'Z' && i - 1 >= 0) {
                base *= 26;
                ans += (s[i - 1] - 'A' + 2) * base;
                --i;
                base *= 26;
            } else {
                ans += (s[i] - 'A' + 1) * base;
                base *= 26;
            }
        }
        return ans;
    }
};
