class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        size_t len = nums.size();
        int sum[len - k + 1];
        int left[len - k + 1];
        int right[len - k + 1];
        int s = 0;
        for (int i = 0; i < k; ++i) {
            s += nums[i];
        }
        sum[0] = s;
        for (int i = 1; i < len - k + 1; ++i) {
            s -= nums[i - 1];
            s += nums[i + k - 1];
            sum[i] = s;
        }
        int max = -1;
        int index = -1;
        for (int i = 0; i < len - k + 1; ++i) {
            if (max < sum[i]) {
                max = sum[i];
                index = i;
            }
            left[i] = index;
        }
        
        max = -1;
        for (int i = len - k; i >= 0; --i) {
            if (max <= sum[i]) {
                max = sum[i];
                index = i;
            }
            right[i] = index;
        }
        vector<int> ans(3,-1);
        int ansMax = -1;
        for (int i = k; i < len - 2 * k + 1; ++i) {
            int j = left[i-k];
            int K = right[i + k];
            if (sum[i] + sum[j] + sum[K] > ansMax) {
                ansMax = sum[i] + sum[j] + sum[K];
                ans[0] = j;
                ans[1] = i;
                ans[2] = K;
            }
        }
        return ans;
    }
};
