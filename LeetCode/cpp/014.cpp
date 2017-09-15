class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        
        string ans = strs[0];
        for (int i = 0; i < strs.size(); i++) {
            string& str = strs[i];
            int j = 0;
            for (; j < str.size() && j < ans.size(); j++) {
                if (str.at(j) != ans.at(j)) {
                    break;
                }
            }
            ans = ans.substr(0,j);
        }
        return ans;
    }
};
