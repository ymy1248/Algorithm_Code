package ymy1248.sup;

import ymy1248.datastructure.*;
import ymy1248.alg.*;

public class Test {
    private static void testBST() {
        BST<Integer, String> bst = new BST<>();

        for (int i = 0; i < 10; i++) {
            bst.insert(i, "val: " + i);
        }
    }

    private static void testShowBST() {
        BST<Integer, String> bst = new BST<>();

        for (int i = 0, j = 0; i < 10; i++) {
            j--;
            bst.insert(i, "val: " + i);
            bst.insert(j, "val: " + j);
        }

        System.out.println("InOrder:");
        Show.bst(bst, 0);
        System.out.println("PreOrder:");
        Show.bst(bst, -1);
        System.out.println("PostOrder:");
        Show.bst(bst, 1);
    }

    private static void testBSTDelete() {
        BST<Integer, String> bst = new BST<>();

        for (int i = 0, j = 0; i < 10; i++) {
            j--;
            bst.insert(i, "val: " + i);
            bst.insert(j, "val: " + j);
        }

        bst.delete(0);
        Show.bst(bst, 0);
    }

    public static void main(String[] args) {
        testBSTDelete();
    }
}
