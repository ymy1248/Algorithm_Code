class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        int i = digits.size();
        while (carry && --i >= 0) {
            digits[i] += 1;
            if (digits[i] == 10) {
                digits[i] = 0;
            } else {
                carry = false;
            }
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};