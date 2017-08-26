import java.util.Arrays;

public class MergeSort{
    public static void sort(int[] nums){
        int[] regs = new int[nums.length];
        sort(nums, regs, 0, nums.length - 1);
    }

    private static void sort(int[] nums, int[] regs, int lo, int hi){
        if (hi <= lo) return;
        int mid = lo + (hi - lo) / 2;
        sort(nums, regs, lo, mid);
        sort(nums, regs, mid + 1, hi);
        merge(nums, regs, lo, mid, hi);
    }

    private static void merge(int[] nums, int[] regs, int lo, int mid, int hi){
        for (int i = lo; i <= hi; i++){
            regs[i] = nums[i];
        }

        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++) {
            if (i > mid) {
                nums[k] = regs[j++];
            } else if (j > hi) {
                nums[k] = regs[i++];
            } else if (regs[j] < regs[i]) {
                nums[k] = regs[j++];
            } else {
                nums[k] = regs[i++];
            }
        }
    }

    public static void main(String[] args) {
        int[] nums = {3,2,5,2,3,4,51,5,35,2,621,5321,621,532,1432,1,216,53,3};
        MergeSort.sort(nums);
        System.out.println(Arrays.toString(nums));
    }
}
