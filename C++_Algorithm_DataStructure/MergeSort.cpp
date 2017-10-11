#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MergeSort {
public:
    static void sort(vector<T> &arr) {
        vector<T> reg (arr.size(), 0);
        sort(arr, reg, 0, arr.size() - 1);
    }

private:
    static void sort(vector<T> &arr, vector<T> &reg, size_t lo, size_t hi) {
        if (hi <= lo) return;
        size_t mid = (lo + hi) / 2;
        sort(arr, reg, lo, mid);
        sort(arr, reg, mid + 1, hi);
        merge(arr, reg, lo, hi);
    }

    static void merge(vector<T> &arr, vector<T> &reg, size_t lo, size_t hi) {
        size_t mid = (lo + hi) / 2;
        
        for (size_t i = lo; i <= hi; ++i) {
            reg[i] = arr[i];
        }

        size_t i = lo;
        size_t j = mid + 1;
        for (size_t k = lo; k < hi + 1; ++k) {
            if (i > mid) {
                arr[k] = reg[j++];
            } else if (j > hi) {
                arr[k] = reg[i++];
            } else {
                if (reg[k] > reg[j]) {
                    arr[k] = reg[j++];
                } else {
                    arr[k] = reg[i++];
                }
            }
        }
    }
};
int main(){
    vector<int> a {10,3,25,4321,5,53,21,432,143,21,65,632,32};
    MergeSort<int>::sort(a);
    
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}
