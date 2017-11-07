class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        char* s = new char [100];
        int state = 0;
        size_t index = 0;
        size_t i = 0, j = 0;
        while (i < source.size()) {
            // cout << i << "," << j << endl;
            if (source[i][j] == '/' && source[i][j + 1] == '/') {
                if (j != 0 && index != 0) {
                    s[index] = 0;
                    ans.push_back(s);
                }
                index = 0;
                i++;
                j = 0;
            } else if (source[i][j] == '/' && source[i][j + 1] == '*') {
                j += 3;
                next(i, j, source);
                if (j == 0 && index != 0) {
                    s[index] = 0;
                    ans.push_back(s);
                    index = 0;
                }
            } else if (j == source[i].size() - 1) {
                s[index++] = source[i][j];
                s[index] = 0;
                if (index != 0) {
                    ans.push_back(s);
                }
                index = 0;
                i++;
                j = 0;
            } else {
                // cout << source[i][j] << endl;
                s[index++] = source[i][j++];
            }
        }
        return ans;
    }
    
    void next(size_t &i, size_t &j, vector<string>& source) {
        while (source[i][j - 1] != '*' || source[i][j] != '/') {
            // cout << i << "," << j << "next"<< endl;
            if (j < source[i].size()) {
                j++;
            } else {
                j = 1;
                i++;
            }
        }
        j++;
        if (j >= source[i].size()) {
            j = 0;
            i++;
        }
    }
};

