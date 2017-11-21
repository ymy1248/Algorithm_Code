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
    list.del();
    list.show();
    list.add(10);
    list.del(8);
    list.show();
    cout << list;
}


int main () {
    Test::testLinkedList();
    return 0;
}
