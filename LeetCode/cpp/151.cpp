class Solution {
public:
    void reverseWords(string &s) {
        string reg = s;
        int end = s.size() - 1;
        int begin = 0;
        int si = 0;

        while (end >= 0 && reg[end--] == ' ') {
        }
        end++;
        while (begin < reg.size() && reg[begin++] == ' ') {
        }
        begin--;

        for (int i = end; i >= begin; --i) {
            if (reg[i] == ' ') {
                for (int j = i + 1; j <= end; ++j) {
                    s[si++] = reg[j];
                }
                if (i != 0) {
                    s[si++] = ' ';
                    while (i - 1 >= 0 && reg[i - 1] == ' ') {
                        --i;
                    }
                    end = i - 1;
                }
            } else if (i == begin) {
                for (int j = i; j <= end; ++j) {
                    s[si++] = reg[j];
                }
            }
        }
        s.resize(si);
    }
};

