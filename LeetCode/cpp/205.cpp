class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> _map;
        unordered_map<char, char> _tmap;
        for (int i = 0; i < s.size(); ++i) {
            auto it = _map.find(s[i]);
            auto tit = _tmap.find(t[i]);
            
            if (it == _map.end()) {
                _map[s[i]] = t[i];
            } else {
                if (it->second != t[i]) {
                    return false;
                }
            }
            
            if (tit == _tmap.end()) {
                _tmap[t[i]] = s[i];
            } else {
                if (tit->second != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
