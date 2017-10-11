class Solution {
public:
    bool hasAlternatingBits(int n) {
        char last = n % 2;
        n = n >> 1;
        while(n != 0) {
            char now = n % 2;
            n = n >> 1;
            if (now == last) {
                return false;
            } else {
                last = now;
            }
        }
        return true;
    }
};
