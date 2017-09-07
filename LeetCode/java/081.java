public class Solution {
    public boolean search(int[] nums, int target) {
        if(nums.length == 0)
            return false;
        return foo(0, nums.length-1, nums, target);
    }
    
    public boolean foo(int begin, int end, int[] nums, int target){
        // System.out.println("begin:" + begin + ", end:" + end);
        if(begin > end){
            return false;
        }
        int left = nums[begin];
        int right = nums[end];
        int mid = (begin + end) / 2;
        if(target == nums[mid] || target == left || target == right)
            return true;
        if(begin == end)
            return false;
        if(nums[mid] > left){
            if(target < nums[mid] && target >= left){
                return foo(begin+1, mid-1, nums, target);
            }else{
                return foo(mid+1, end-1, nums, target);
            }
        }else if (nums[mid] < left){
            if(target > nums[mid] && target <= right){
                return foo(mid+1, end-1, nums, target);
            }else{
                return foo(begin+1, mid-1, nums, target);
            }
        } else {
            return foo(begin, end - 1, nums, target);
        }
    }
}
