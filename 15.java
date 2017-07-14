public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        System.out.println(Arrays.toString(nums));
        for(int i = 0; i<nums.length - 2; i++){
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int l = i + 1, r = nums.length - 1; l < r;){
                if(nums[l] + nums[r] == -nums[i]){
                    ans.add(Arrays.asList(nums[i], nums[l], nums[r]));
                    while(l < r && nums[l] == nums[l+1]){
                        l++;
                    }
                    while(l < r && nums[r] == nums[r-1]){
                        r--;
                    }
                    l++;
                    r--;
                }else if(nums[l] + nums[r] < -nums[i]){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return ans;
    }
}
