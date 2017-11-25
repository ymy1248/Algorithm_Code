class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int ans = nums[0];
        int amax = ans;
        int amin = ans;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                swap(amax, amin);
            }
            amax = max(amax * nums[i], nums[i]);
            amin = min(amin * nums[i], nums[i]);
            ans = max(ans, amax);
        }
        return ans;
    }
};
