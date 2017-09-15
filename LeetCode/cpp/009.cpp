class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) {
            return true;
        }
        if (x < 0 || x % 10 == 0) {
            return false;
        }
        if ( x < 10) {
            return true;
        }
        int sum = 0;
        
        while (x > sum) {
            sum *= 10;
            sum += x % 10;
            x /= 10;
        }
        
        // cout << "sum:" << sum << endl;
        // cout << "x: "<< x << endl;
        if (sum == x || sum / 10 == x) {
            return true;
        } else {
            return false;
        }
    }
};
