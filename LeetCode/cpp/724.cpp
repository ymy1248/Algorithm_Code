class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0) {
            return -1;
        }
        long left[nums.size()];
        long right[nums.size()];
        
        int sum = 0;
        
        for (int i = nums.size() - 1; i >= 0; --i) {
            sum += nums[i];
            right[i] = sum;
        }
        
        sum = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (right[i + 1] == sum) {
                return i;
            }
            sum += nums[i];
        }
        if (sum == 0) {
            return nums.size() - 1;
        }
        return -1;
    }
};
