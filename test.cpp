#include <iostream>

using namespace std;
class A {
public:
    A(int n){
        this->n = n;
    };
    int n;
};

int main() {
    int&& a = 1;
    cout << a << endl;
}
