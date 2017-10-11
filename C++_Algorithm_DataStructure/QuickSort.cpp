#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class QuickSort {
public:
    static void sort(vector<T> &arr) {
        sort(arr, 0, arr.size() - 1);
    }

private:
    static void sort(vector<T> &arr, size_t lo, size_t hi) {
        if (hi <= lo) return;
        size_t j = partition(arr, lo, hi);
        sort(arr, lo, j - 1);
        sort(arr, j + 1, hi);
    }

    static size_t partition(vector<T> &arr, size_t lo, size_t hi) {
        T piv = arr[lo];
        size_t i = lo;
        size_t j = hi + 1;
        
        while (true) {
            while (arr[++i] < piv) {
                if(i == hi) break;
            }
            while (arr[--j] > piv) {
                if(j == lo) break;
            }
            if (i >= j) {
                break;
            }
            T reg = arr[i];
            arr[i] = arr[j];
            arr[j] = reg;
        }
        T reg = arr[j];
        arr[j] = arr[lo];
        arr[lo] = reg;
        return j;
    }
};

int main() {
    vector<int> a {10,3,25,4321,5,53,21,432,143,21,65,632,32};
    QuickSort<int>::sort(a);
    
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}
