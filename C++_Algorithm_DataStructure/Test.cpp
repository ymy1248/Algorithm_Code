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

int main () {
    Test::testQuickSort();
}
