package ymy1248.alg;

@SuppressWarnings({"rawtypes", "unchecked"})
public class MergeSort{
    public static void sort(Comparable[] comps){
        Comparable[] regs = new Comparable[comps.length];
        sort(comps, regs, 0, comps.length - 1);
    }

    private static void sort(Comparable[] comps, Comparable[] regs, int lo, int hi){
        if (hi <= lo) return;
        int mid = lo + (hi - lo) / 2;
        sort(comps, regs, lo, mid);
        sort(comps, regs, mid + 1, hi);
        merge(comps, regs, lo, mid, hi);
    }

    private static void merge(Comparable[] comps, Comparable[] regs, int lo, int mid, int hi){
        for (int i = lo; i <= hi; i++){
            regs[i] = comps[i];
        }

        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++) {
            if (i > mid) {
                comps[k] = regs[j++];
            } else if (j > hi) {
                comps[k] = regs[i++];
            } else if (regs[j].compareTo(regs[i]) < 0) {
                comps[k] = regs[j++];
            } else {
                comps[k] = regs[i++];
            }
        }
    }

}
