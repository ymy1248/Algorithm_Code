class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int hi = nums.size() - 1;
        
        for (int lo = 0; lo <= hi; lo++) {
            while (nums[hi] == val && hi >= 0) {
                hi--;
            }
            if (nums[lo] == val && lo != hi) {
                swap(nums[hi], nums[lo]);
            }
        }
        
        return hi + 1;
    }
};
