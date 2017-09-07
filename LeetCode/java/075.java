class Solution {
    public void sortColors(int[] nums) {
        // counting sort
        int[] hash = new int[3];
        for (int i: nums) {
            hash[i]++;
        }
        // System.out.println(Arrays.toString(hash));
        
        int p = 0;
        for (int i = 0; i < 3; i++) {
            if (hash[i] != 0){
                for (int j = p; j < p + hash[i]; j++) {
                    nums[j] = i;
                }
            }
            p += hash[i];
        }
    }
}
