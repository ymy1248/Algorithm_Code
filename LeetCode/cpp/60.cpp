class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        vector<int> nums;
        int sum = 1;
        // nums.push_back(0);
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
            sum *= i;
        }
        cout << sum << endl;
        k -= 1;
        for (int i = n; i > 0; --i) {
            sum /= i;
            int index = k / sum;
            s += to_string(nums[index]);
            // cout << i << endl;
            // cout << "sum: " << sum << endl;
            // cout << "index: " << index << endl;
            // cout << "k: " << k << endl;
            // cout << endl;
            nums.erase(nums.begin() + index);
            k %= sum;
        }
        return s;
    }
};
