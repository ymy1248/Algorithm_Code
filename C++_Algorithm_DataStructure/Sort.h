/**
 * @author: ymy1248
 */
#include <vector>
#include "consts.h"

using namespace std;

namespace ymy1248 {
class Sort {
public:
    template <typename T>
    static void quickSort(vector<T> &arr) {
        quickSort(arr, 0, arr.size() - 1);
    }

    template <typename T>
    static void mergeSort(vector<T> &arr) {
    }

private:
    template <typename T>
    static void quickSort(vector<T> &arr, size_t lo, size_t hi) {
        size_t mid = partition(arr, lo, hi);
        quickSort(arr, lo, mid - 1);
        quickSort(arr, mid + 1, hi);
    }

    template <typename T>
    static size_t partition(vector<T> &arr, size_t lo, size_t hi) {
        T piv = arr[lo];
        size_t i = lo;
        size_t j = hi + 1;

        while (true) {
            while (arr[++i] > piv) {
                if (i >= hi) {
                    break;
                }
            }

            while (arr[--j] < piv) {
                if (j <= lo) {
                    break;
                }
            }
            if (i >= j) {
                break;
            }
            swap(arr, i, j);
        }
        swap(arr, lo, j);
        return j;
    }

    template <typename T>
    static inline void swap(vector<T> &arr, size_t i, size_t j) {
        T reg = arr[i];
        arr[i] = arr[j];
        arr[j] = reg;
    }
};
}
