#include "template.h"
int main() {
    int row;
    cin >> row;
    
    int level = 1;
    for (int i = 0; i < row - 1; ++i) {
        level += 2;
    }
    int mid = level / 2;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < level; ++j) {
            if (j >= mid - i && j <= mid + i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    cout << endl;
    for (int i = row - 1; i >= 0; --i) {
        for (int j = 0; j < level; ++j) {
            if (j >= mid - i && j <= mid + i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;

}
