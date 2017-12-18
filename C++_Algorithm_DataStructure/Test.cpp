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
    cout << list;
    list.add(8).add(1);
    cout << list;
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
    bst.add(5, "5").add(1, "1").add(9, "9");
    bst.add(6, "6").add(7, "7").add(8,"8").add(3,"3").add(2,"2");
    bst.add(19, "19").add(100, "100");
    cout << bst;
}

void Test::testDeque() {
    Deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);
    dq.push_back(6);
    dq.push_back(7);
    cout << dq;
    dq.pop_back();
    cout << "dq.pop_back();" << endl;
    cout << dq;
    dq.pop_front();
    cout << "dq.pop_front();" << endl;
    cout << dq;
    dq.push_front(-1);
    cout << "dq.push_front(-1);" << endl;
    cout << dq;
}

int main () {
    Test::testBST();
    return 0;
}
