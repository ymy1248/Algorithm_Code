#include "Test.h"

using namespace ymy1248;

void Test::testShow1DVector() {
    vector<int> a {1,2,3,4,5,6,7};
    Show::vector_(a);
}

void Test::testQuickSort() {
    vector<int> a {5,42,51,5,2,1,6,32,64,32,2};
    Show::vector_(a);
    Sort::quickSort(a);
    Show::vector_(a); 
}

void Test::testLinkedList() {
    LinkedList<int> list;
    list.add(0);
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(6);
    list.add(7);
    Show::linkedList(list);
    cout << "contains 3: " << list.contains(3) << endl;
    cout << "contains 100: " << list.contains(100) << endl;
    list.clear();
    list.add(4);
    list.add(6);
    list.show();
    list.add(8).add(1);
    list.show();
    try {
        list.del();
    } catch (string& s) {
        cout << s << endl;
    }
    list.show();
    list.add(10);
    list.del(8);
    list.show();
    cout << list;
}

void Test::testBST() {
    BST<int, string> bst;
    bst.add(0, "0");
    bst.add(10, "10");
    bst.add(-1, "-1");
    bst.add(9, "9");
    cout << bst.contains(0) << endl;
    cout << "bst.contains(9): " << bst.contains(9) << endl;
    cout << "delete 9" << endl;
    bst.del(9);
    cout << "bst.contains(9): " << bst.contains(9) << endl;
}


int main () {
    Test::testBST();
    return 0;
}
