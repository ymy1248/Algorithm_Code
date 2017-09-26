class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans, nums, vector<int>(), 0);
        return ans;
    }

private:
    void backtrack(vector<vector<int>> &ans, const vector<int> &nums, vector<int> subAns, size_t dim) {
        if (dim == nums.size()) {
            ans.push_back(subAns);
        } else {
            for (size_t i = 0; i < nums.size(); ++i) {
                if (contains(subAns, nums[i])) {
                    continue;
                } else {
                    vector<int> newAns = subAns;
                    newAns.push_back(nums[i]);
                    backtrack(ans, nums, newAns, dim + 1);
                }
            }
        }
    }
    
    bool contains(const vector<int> &arr, int n) {
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[i] == n) {
                return true;
            }
        }
        return false;
    }
};
