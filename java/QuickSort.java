import java.util.*;

public class QuickSort{
    public static void sort(int[] nums){
        sort(nums, 0, nums.length - 1);
    }

    private static void sort(int[] nums, int lo, int hi){
        if(hi <= lo) return;
        int j = partition(nums, lo, hi);
        sort(nums, lo, j-1);
        sort(nums, j+1, hi);
    }

    private static int partition(int[] nums, int lo, int hi){
        int i = lo;
        int j = hi + 1;
        int v = nums[lo];
        while(true){
            while(nums[++i] < v)
                if(i == hi) break;
            while(nums[--j] > v)
                if(j == lo) break;
            if(i >= j) break;
            swap(nums, i, j);
        }
        swap(nums, lo, j);
        return j;
    }

    private static void swap(int[] nums, int i, int j){
        int reg = nums[i];
        nums[i] = nums[j];
        nums[j] = reg;
    }
    public static void main(String[] args){
       int[] nums = {3,2,4,4,5,215,321,5,21,632,16,43,3};
       QuickSort.sort(nums);
       System.out.println(Arrays.toString(nums));
    }
}
