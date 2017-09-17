class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int *array = new int[len];
        int max = nums[0];
        
        array[0] = nums[0];
        
        for (int i = 1; i < len; i++) {
            array[i] = nums[i] + (array[i - 1] < 0 ? 0 : array[i - 1]);
            max = max > array[i] ? max : array[i];
        }
        return max;
    }
};
