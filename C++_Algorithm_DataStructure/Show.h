/**
 * @author: ymy1248
 */
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

namespace ymy1248 {
    class Show {
    public:
        // template <typename T, typename A>
        // static void vector_(const vector<T, A> &arr);
        template <typename T, typename A>
        static void vector_(const vector<T, A> &arr) {
            for (size_t i = 0; i < arr.size(); ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        template <typename T, typename A>
        static void vector_(const vector<vector<T,A>> &arr) {
            for (size_t i = 0; i < arr.size(); ++i) {
                for (size_t j = 0; j < arr.size(); ++j) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    };
}
