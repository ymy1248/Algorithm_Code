package ymy1248.sup;

public class Show {
    public static void showArray(Object[] array){
        System.out.print("[");
        for (int i = 0; i < array.length - 1; i++) {
           System.out.print(array[i] + ", ");
        }
        System.out.println(array[array.length - 1] + "]");
    }

    public static void showArray(Object[][] array){
        for (Object[] subArray: array) {
            showArray(subArray);
        }
    }

    public static void main(String[] args){
        Integer[] nums = {1,2,3,4,5,6,7};
        showArray(nums);
    }
}
