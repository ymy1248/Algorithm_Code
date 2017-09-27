class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> sub;
        backtrack(ans, s, sub, -1);
        return ans;
    }
    
private:
    void backtrack(vector<string> &ans, string &s, vector<string> &sub, int end) {
        // cout << "end: " << end << endl;
        // for (size_t i = 0; i < sub.size(); ++i) {
        //     cout << sub[i] << " ";
        // }
        // cout << endl;
        if (sub.size() == 4 && end == s.size() - 1) {
            string ip;
            for(size_t i = 0; i < 3; ++i) {
                ip += sub[i] + ".";
            }
            ip += sub[3];
            ans.push_back(ip);
        } else {
            int n = sub.size();
            if (s.size() - end - 1 > (4 - n) * 3 || s.size() - end - 1 < 4 - n){
                return;
            } else {
                for (size_t i = 1; i < 4 && end + i < s.size(); ++i) {
                    if (s[end + 1] == '0' && i != 1) continue;
                    string strip = s.substr(end + 1, i);
                    // cout << "strip: " << strip << endl;
                    int intip = stoi(strip);
                    if (intip <= 255 && intip >= 0){
                        sub.push_back(strip);
                        backtrack(ans, s, sub, end + i);
                        sub.pop_back();
                    }
                }
            }
        }
    }
};
