class Solution {
public:
    int countPrimes(int n) {
        n--;
        int ans = 0;
        vector<bool> arr(n + 1, true);
        arr[1] = false;
        
        for (size_t i = 2; i < n + 1; ++i) {
            for (size_t j = i; i*j < n + 1; ++j) {
                if (arr[i] == false) {
                    break;
                }
                arr[i * j] = false;
            }
        }
        
        
        for (size_t i = 1; i < n + 1; ++i) {
            if (arr[i] == true) {
                ++ans;
            }
            // cout << i << ": " << arr[i] << " ";
        }
        // cout << endl;
        return ans;
    }
};
