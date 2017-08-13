c class Solution {
    public int search(int[] nums, int target) {
        if(nums.length == 0)
            return -1;
        return foo(0, nums.length-1, nums, target);
    }
    
    public int foo(int begin, int end, int[] nums, int target){
        // System.out.println("begin:" + begin + ", end:" + end);
        if(begin > end){
            return -1;
        }
        int left = nums[begin];
        int right = nums[end];
        int mid = (begin + end) / 2;
        if(target == nums[mid])
            return mid;
        if(target == left)
            return begin;
        if(target == right)
            return end;
        if(begin == end)
            return -1;
        if(nums[mid] > left){
            if(target < nums[mid] && target >= left){
                return foo(begin+1, mid-1, nums, target);
            }else{
                return foo(mid+1, end-1, nums, target);
            }
        }else{
            if(target > nums[mid] && target <= right){
                return foo(mid+1, end-1, nums, target);
            }else{
                return foo(begin+1, mid-1, nums, target);
            }
        }
    }
}
