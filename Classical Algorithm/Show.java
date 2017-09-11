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
    public static void bst(BST b, int mode) {
        bst(b.root, mode);
        System.out.println();
    }

    private static void bst(BSTNode node, int mode) {
        if (node == null){
            return;
        }
        if (mode == 0) {
            bst(node.left, mode);
            System.out.print(node.key + " ");
            bst(node.right, mode);
        } else if (mode < 0) {
            System.out.print(node.key + " ");
            bst(node.left, mode);
            bst(node.right, mode);
        } else {
            bst(node.left, mode);
            bst(node.right, mode);
            System.out.print(node.key + " ");
        }
    }
}
