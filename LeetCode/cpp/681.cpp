#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {
		int h0 = time[0] - '0';
        int h1 = time[1] - '0';
        int m0 = time[3] - '0';
        int m1 = time[4] - '0';
        if (h0 == h1 && m0 == m1 && m0 == h1) {
            string ans;
            ans += to_string(h0);
            ans += to_string(h1);
            ans += ":";
            ans += to_string(m0);
            ans += to_string(m1);
            return ans;
        }
        int num[] = {h0, h1, m0, m1};
        int min = INT_MAX;
        string ans;
        const int nowH = num[0] * 10 + num[1];
        const int nowM = num[2] * 10 + num[3];

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    for (int z = 0; z < 4; ++z) {
                        if (num[i] > 2 || num[k] > 5 || (num[i] == 2 && num[j] > 3)) {
                            continue;
                        }
                        int next[] = {num[i], num[j], num[k], num[z]};
                        int d = differ(nowH, nowM, next);
                        if (min > d && d != 0) {
                            min = d;
                            ans = "";
                            ans += to_string(next[0]);
                            ans += to_string(next[1]);
                            ans += ":";
                            ans += to_string(next[2]);
                            ans += to_string(next[3]);
                        }
                    }
                }
            }
        }
        return ans;
    }

	int differ(const int nowH, const int& nowM, int* next) {
        int diff = 0; 
        int nextH = next[0] * 10 + next[1]; 
        int nextM = next[2] * 10 + next[3]; 

        if (nextH < nowH || (nextH == nowH && nextM < nowM)) {
            diff += (23 - nowH) * 60;
            diff += (59 - nowM);
            diff += nextH * 60;
            diff += nextM;
        } else {
            diff += (nextH - nowH) * 60;
            diff += (nextM - nowM);
        }
        return diff;
    }
};

