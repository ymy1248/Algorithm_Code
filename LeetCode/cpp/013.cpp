class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ) {
            if (i < s.size() - 1 && s.at(i) == 'I' && s.at(i+1) == 'V') {
                ans += 4;
                i += 2;
            } else if (i < s.size() - 1 && s.at(i)  == 'I' && s.at(i+1) == 'X') {
                ans += 9;
                i += 2;
            } else if (i < s.size() - 1 && s.at(i)  == 'X' && s.at(i+1) == 'L') {
                ans += 40;
                i += 2;
            } else if (i < s.size() - 1 && s.at(i)  == 'X' && s.at(i+1) == 'C') {
                ans += 90;
                i += 2;
            } else if (i < s.size() - 1 && s.at(i)  == 'C' && s.at(i+1) == 'D') {
                ans += 400;
                i += 2;
            } else if (i < s.size() - 1 && s.at(i)  == 'C' && s.at(i+1) == 'M') {
                ans += 900;
                i += 2;
            } else if (s.at(i)  == 'I') {
                ans += 1;
                i += 1;
            } else if (s.at(i)  == 'V') {
                ans += 5;
                i += 1;
            } else if (s.at(i)  == 'X') {
                ans += 10;
                i += 1;
            } else if (s.at(i)  == 'L') {
                ans += 50;
                i += 1;
            } else if (s.at(i)  == 'C') {
                ans += 100;
                i += 1;
            } else if (s.at(i)  == 'D') {
                ans += 500;
                i += 1;
            } else {
                ans += 1000;
                i += 1;
            }
        }
        return ans;
    }
};
