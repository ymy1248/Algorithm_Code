class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return func(nums, 0, nums.size() - 1, target);
    }
    
    int func(vector<int>& nums, int lo, int hi, int target) {
        int mid = (lo + hi) / 2;
        // cout << "lo: " << lo << ", hi:" << hi << "\n";
        if (lo == hi) {
            if (target > nums[hi]){
                return hi + 1;
            }
            return hi;
        }
        if (target > nums[mid]) {
            return func(nums, mid + 1, hi, target);
        } else if (target < nums[mid]) { 
            return func(nums, lo, mid, target);
        } else {
            return mid;
        }
    }
};
