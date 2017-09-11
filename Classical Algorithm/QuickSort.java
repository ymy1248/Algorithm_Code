package ymy1248.alg;

public class QuickSort{
    public static void sort(Comparable[] comps){
        sort(comps, 0, comps.length - 1);
    }

    private static void sort(Comparable[] comps, int lo, int hi){
        if(hi <= lo) return;
        int j = partition(comps, lo, hi);
        sort(comps, lo, j-1);
        sort(comps, j+1, hi);
    }

    private static int partition(Comparable[] comps, int lo, int hi){
        int i = lo;
        int j = hi + 1;
        Comparable p = comps[lo];
        while(true){
            while(comps[++i].compareTo(p) < 0)
                if(i == hi) break;
            while(comps[--j].compareTo(p) > 0)
                if(j == lo) break;
            if(i >= j) break;
            swap(comps, i, j);
        }
        swap(comps, lo, j);
        return j;
    }

    private static void swap(Comparable[] comps, int i, int j){
        Comparable reg = comps[i];
        comps[i] = comps[j];
        comps[j] = reg;
    }
}
