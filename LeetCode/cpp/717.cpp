class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size() <= 1) {
            return true;
        }
        size_t i = 0;
        while (i < bits.size() - 1) {
            if (bits[i] == 1 && bits[i+1] == 1) {
                i += 2;
            } else if (bits[i] == 1 && bits[i+1] == 0) {
                i += 2;
            } else if (bits[i] == 0) {
                i += 1;
            }
        }
        // cout << i << endl;
        if (i == bits.size() - 1) {
            return true;
        } else {
            return false;
        }
    }
};
