class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> _set;
        unordered_set<string> v_set;
        vector<string> ans;
        if (s.size() < 10) {
            return ans;
        }
        for (int i = 0; i <= s.size() - 10; ++i) {
            // cout << i << endl;
            string str = s.substr(i, 10);
            if (_set.find(str) == _set.end()) {
                _set.insert(str);
            } else if (v_set.find(str) == v_set.end()){
                v_set.insert(str);
                ans.push_back(str);
            }
        }
        return ans;
    }
};
