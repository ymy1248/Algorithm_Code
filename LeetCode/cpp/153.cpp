class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }

private:
    int findMin(vector<int>& nums, int lo, int hi) {
        // cout << "lo: " << lo << ", hi: " << hi << endl;
        if (lo == hi) {
            return nums[lo];
        }
        int mid = (lo + hi) / 2;
        if (nums[lo] < nums[hi]) {
            return nums[lo];
        }
        if (nums[mid] < nums[hi]) {
            return findMin(nums, lo + 1, mid);
        } else {
            return findMin(nums, mid + 1, hi);
        }
    }
};
