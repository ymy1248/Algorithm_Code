class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }
        int lo = 0, hi = s.size() - 1;
        while (lo < hi) {
            while (s[lo] < '0' || (s[lo] > '9' && s[lo] < 'A' ) || (s[lo] > 'Z' && s[lo] < 'a') || s[lo] > 'z') {
                if (++lo >= s.size()) break;
            }
            while (s[hi] < '0' || (s[hi] > '9' && s[hi] < 'A' )  || (s[hi] > 'Z' && s[hi] < 'a') || s[hi] > 'z') {
                // cout << s[hi] << endl;
                if (--hi < 0) break;            
            }
            // cout << "lo: " << lo << " hi: " << hi << endl;
            if (s[lo] == s[hi]) {
                // cout << "==" << endl;
                ++lo;
                --hi;
                continue;
            }
            if ((s[lo] >= 'A' && s[lo] <= 'Z') && s[lo] != s[hi] - 32) {
                // cout << "AZ" << endl;
                return false;
            }
            if ((s[lo] >= 'a' && s[lo] <= 'z') && s[lo] != s[hi] + 32) {
                // cout << "az" << endl;
                return false;
            }
            if ((s[lo] >= '0' && s[lo] <= '9') && s[lo] != s[hi]) {
                return false;
            }
            ++lo;
            --hi;
        }
        return true;
    }
};
