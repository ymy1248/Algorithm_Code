public class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans = {-1,-1};
        if(nums.length == 0) return ans;
        int pos = Arrays.binarySearch(nums, target);
        if(pos<0) return ans;
        ans[0] = pos;
        ans[1] = pos;
        while(ans[0] - 1 >= 0 && nums[ans[0] - 1] == target)
            ans[0]--;
        while(ans[1] + 1 < nums.length && nums[ans[1] + 1] == target)
            ans[1]++;
        return ans;
    }
}
