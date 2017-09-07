class Solution {
    public int removeDuplicates(int[] nums) {
        int numL = nums.length;
        if (numL == 0 || numL == 1 || numL == 2) {
            return numL;
        }
        
        int last = nums[0];
        int count = 0;
        int len = 0;
        
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == last) {
                if (count == 0){
                    count++;
                    nums[++len] = nums[i];
                }
            } else {
                last = nums[i];
                count = 0;
                nums[++len] = nums[i];
            }
        }
        return len + 1;
    }
}
