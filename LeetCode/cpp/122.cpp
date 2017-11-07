class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int pro = 0;
        int pri = 0;
        bool have = false;
        size_t i = 0;
        while(i < prices.size() - 1) {
            if (!have) {
                while (i < prices.size() - 1 && prices[i] >= prices[i + 1]) {
                    ++i;
                }
                have = true;
                pri = prices[i];
            } else {
                while (i < prices.size() - 1 && prices[i] <= prices[i + 1]) {
                    ++i;
                }
                have = false;
                pro += prices[i] - pri;
            }
        }
        if (have) {
            pro += prices[prices.size() - 1] - pri;
        }
        return pro;
    }
};
