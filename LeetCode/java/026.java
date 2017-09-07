class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 1 || nums.length == 0) {
            return nums.length;
        }
        int last = nums[0];
        int len = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != last) {
                len++;
                last = nums[i];
                nums[len] = last;
            }
        }
        
        return len + 1;
    }
}
