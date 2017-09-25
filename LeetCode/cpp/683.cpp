class Solution {
    public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int min = INT_MAX;
        int days[20001];
        for (size_t i = 0; i < flowers.size(); ++i) {
            days[flowers[i]] = i + 1;
        }
        // for (size_t i = 1; i < flowers.size() + 1; ++i) {
        //     cout << days[i] << "," ;
        // }
        // cout << endl;
        for (size_t lo = 1, hi = k + 2; hi < flowers.size() + 1;) {
            for (int i = lo + 1; i < hi + 1; ++i) {
                // cout << "days[i]: " << days[i] << endl;
                if ((days[i] < days[lo] || days[i] < days[hi]) && i != hi) {
                    // cout << "days[i]: " << days[i] << ", lo:" << days[lo] << ", hi:" << days[hi] << endl;
                    break;
                }
                if (i == hi) {
                    int maxDay = days[lo] > days[hi] ? days[lo] : days[hi];
                    // cout << lo << ":" << days[lo] << "," << hi  << ":" << days[hi] << endl;
                    min = min < maxDay ? min : maxDay;
                }
            }
            ++lo;
            ++hi;
        }
        return min == INT_MAX ? -1 : min;
    }
};
