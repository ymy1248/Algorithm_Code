#include "Test.h"

using namespace ymy1248;

void Test::testShow1DVector() {
    vector<int> a {1,2,3,4,5,6,7};
    Show::vector_(a);
}

int main () {
    Test::testShow1DVector();
}
