class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> set;
        for (size_t i = 0; i < words.size(); ++i) {
            set.insert(words[i]);
        }
        sort(words.begin(), words.end());
        size_t max = 0;
        string reg = "";
        for (size_t i = 0; i < words.size(); ++i) {
            char* s = const_cast<char*>(words[i].c_str());
            bool flag = true;
            string sReg = words[i];
            for (int j = words[i].size() - 1; j >= 1; --j) {
                s[j] = '\0';
                // cout << j << endl;
                // cout << s << endl;
                auto it = set.find(s);
                if (it == set.end()) {
                    // cout << "can't" << endl;
                    flag = false;
                    break;
                }
            }
            if (flag && words[i].size() > max) {
                // cout << "new max: "<< words[i] << endl;
                reg = sReg;
                max = sReg.size();
            }
        }
        return reg;
    }
};
