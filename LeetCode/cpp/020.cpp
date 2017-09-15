class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        for (int i = 0; i < s.length(); i++) {
            if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[') {
                left.push(s.at(i));
            } else {
                if (left.empty()) {
                    return false;
                }
                if (s.at(i) == ')' && left.top() != '(') {
                    return false;
                } else if (s.at(i) == '}' && left.top() != '{') {
                    return false;
                } else if (s.at(i) == ']' && left.top() != '['){
                    return false;
                }
                left.pop();
            }
        }
        if (left.empty()) {
            return true;
        } else {
            // cout << "size";
            return false;
        }
    }
};
