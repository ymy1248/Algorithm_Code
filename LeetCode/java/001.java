class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hash = new HashMap<>();
        int[] ans = new int[2];
        
        for (int i = 0; i < nums.length; i++) {
            int diff = target - nums[i];
            if (hash.containsKey(diff)) {
                ans[0] = hash.get(diff);
                ans[1] = i;
            } else {
                hash.put(nums[i], i);
            }
        }
        return ans;
    }
}
