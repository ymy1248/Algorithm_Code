class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 0;
        int c = 0;
        int reg = -1;
        for (size_t i = 0; i <= chars.size(); ++i) {
            if (i != chars.size() && chars[i] == reg) {
                c++;
            } else {
                if (c > 0) {
                    c++;
                    int creg = c;
                    while (c > 0) {
                        c /= 10;
                        count++;
                    }
                    int ct = count - 1;
                    while (creg > 0) {
                        // cout << "ct: " << ct;
                        chars[ct] = '0' + creg % 10;
                        creg /= 10;
                        ct--;
                    }
                }
                reg = chars[i];
                chars[count] = reg;
                // cout << i << ", count: " << chars[count] << " " << endl;
                count++;
            }
        }
        return count - 1;
    }
};

