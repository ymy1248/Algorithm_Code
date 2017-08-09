public class Solution {
    public void nextPermutation(int[] nums) {
        int i = nums.length-1;
        while(i > 0 && nums[i] <= nums[i-1]){
            i--;
        }
        // System.out.println(i);
        if(i == 0){
            reverse(nums, 0, nums.length-1);
            return;
        }
        i--;
        int j = i + 1;
        while(j+1<nums.length && nums[j+1] > nums[i]){
            j++;
        }
        swap(nums, i, j);
        // System.out.println(Arrays.toString(nums));
        reverse(nums, i+1, nums.length-1);
    }
    
    public void swap(int[] nums, int i, int j){
        int reg = nums[i];
        nums[i] = nums[j];
        nums[j] = reg;
    }
    
    public void reverse(int[] nums, int begin, int end){
        while(begin < end){
            swap(nums, begin++, end--);
        }
    }
}
