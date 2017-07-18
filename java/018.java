public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new LinkedList<>();
        // System.out.println(Arrays.toString(nums));
        
        if(nums.length < 4){
            return ans;
        }
        
        for(int i = 0; i<nums.length-3; i++){
            for(int j = i+1; j<nums.length-2; j++){
                int sum = target - nums[i] - nums[j];
                for(int k = j+1, l = nums.length-1; k<l;){
                    int[] show = {nums[i], nums[j], nums[k], nums[l]};
                    // System.out.println(Arrays.toString(show));
                    int klsum = nums[k] + nums[l];
                    // System.out.println("sum:" + sum + ", klsum:" + klsum);
                    if(klsum > sum){
                        // System.out.println("klsum > sum");
                        l--;
                    } else if(klsum < sum){
                        k++;
                    } else{
                        ans.add(Arrays.asList(nums[i], nums[j], nums[k], nums[l]));
                        l--;
                        k++;
                    }
                    while(k != j+1 && k<l && nums[k] == nums[k-1]){
                        k++;
                    }
                    while(l != nums.length-1 && k<l && nums[l] == nums[l+1]){
                        // System.out.println("duplicate l");
                        l--;
                    }
                    // System.out.println("k:" + k + ", l:" + l);
                }
                while(nums[j] == nums[j+1] && j<nums.length-2){
                    j++;
                }
            }
            while(nums[i] == nums[i+1] && i<nums.length-3){
                i++;
            }
        }
        return ans;
    }
}
