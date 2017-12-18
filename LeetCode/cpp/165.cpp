#include "template.h"

class Solution {
public:
    int compareVersion(string v1, string v2) {
        int dot1 = -1;
        int dot2 = -1; 

        while (++dot1 < v1.size() && v1[dot1] != '.') {
        }

        while (++dot2 < v2.size() && v2[dot2] != '.') {
        }

        cout << "dot1: " << dot1 << endl;
        cout << "dot2: " << dot2 << endl;

        int v1l = 0, v1r = 0, v2l = 0, v2r = 0;
        if (dot1 >= v1.size()) {
            v1l = stoi(v1);
        } else {
            v1l = stoi(v1.substr(0, dot1));
            v1r = stoi(v1.substr(dot1 + 1, v1.size() - dot1 + 1));
        }

        if (dot2 >= v2.size()) {
            v2l = stoi(v2);
        } else {
            v2l = stoi(v2.substr(0, dot2));
            v2r = stoi(v2.substr(dot2 + 1, v2.size() - dot2 + 1));
        }


        cout << v1l << " " << v1r << endl;
        cout << v2l << " " << v2r << endl;

        if (v1l > v2l) {
            return 1;
        } else if (v1l < v2l) {
            return -1;
        } else if (v1r > v2r) {
            return 1;
        } else if (v1r < v2r) {
            return -1;
        } else {
            return 0;
        }
    }
};

int main() {
    while (true) {
        string v1, v2;
        Solution s;
        cin >> v1 >> v2;
        cout << s.compareVersion(v1, v2) << endl;
    }
}
