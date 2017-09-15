package ymy1248.sup;

import ymy1248.datastructure.*;

public class Show {
    public static void array(Object[] array){
        System.out.print("[");
        for (int i = 0; i < array.length - 1; i++) {
           System.out.print(array[i] + ", ");
        }
        System.out.println(array[array.length - 1] + "]");
    }
    
    public static void array(Object[][] array){
        for (Object[] subArray: array) {
            array(subArray);
        }
    }

    /**
     * @param mode which kind of show mode we prefer
     * mode less than 0: preorder
     * mode equals 0: inorder
     * mode greater than 0: postorder
     */
    @SuppressWarnings("rawtypes")
    public static void bst(BST b, int mode) {
        System.out.println(b.toString(mode));
        System.out.println();
    }


    @SuppressWarnings("rawtypes")
    public static void linkedList(LinkedList list) {
        System.out.println(list);
    }
}
