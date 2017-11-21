class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() <= 3) {
            int max = 0;
            for (int i = 0; i < nums.size(); ++i) {
                max = max > nums[i] ? max : nums[i];
            }
            return max;
        }
        vector<int> dpT(nums.size() - 3, -1);
        dpT[0] = nums[1];
        dpT[1] = nums[1] > nums[2] ? nums[1] : nums[2];
        vector<int> dpF(nums.size() - 1, -1);
        dpF[0] = nums[0];
        dpF[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        for (int i = 2; i < nums.size() - 1; ++i) {
            dpF[i] = dpF[i - 1] > dpF[i - 2] + nums[i] ? dpF[i - 1] : dpF[i - 2] + nums[i];
        }
        for (int i = 3; i < nums.size() - 2; ++i) {
            dpT[i - 1] = dpT[i - 2] > dpT[i - 3] + nums[i] ? dpT[i - 2] : dpT[i - 3] + nums[i];
        }
//         cout << "dpT: ";
//         for (int i = 0; i < dpT.size(); ++i) {
//             cout << dpT[i] << " ";
//         }
//         cout << endl;
        
//         cout << "dpF: ";
//         for (int i = 0; i < dpF.size(); ++i) {
//             cout << dpF[i] << " ";
//         }
//         cout << endl;
        
        return dpF[dpF.size() - 1] > dpT[dpT.size() - 1] + nums[nums.size() - 1] ?
            dpF[dpF.size() - 1] : dpT[dpT.size() - 1] + nums[nums.size() - 1];
    }
};
