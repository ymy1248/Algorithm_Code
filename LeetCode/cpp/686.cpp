class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int count = 1;
        string reg = A;
        while (A.find(B) == string::npos && A.size() <= B.size() + 2 * reg.size()) {
            A += reg;
            count++;
        }
        if (A.size() > B.size() + 2 * reg.size()) {
            return -1;
        }
        return count;
    }
};
