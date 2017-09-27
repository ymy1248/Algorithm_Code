class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        bool *table = new bool [nums.size()];
        for (size_t i = 0; i < nums.size(); ++i) {
            table[i] = false;
        }
        sort(nums.begin(), nums.end());
        backtrack(ans, nums, sub, table);
        return ans;
    }
private:
    void backtrack(vector<vector<int>> &ans, const vector<int> &nums, vector<int> &sub, bool table[]) {
        if (nums.size() == sub.size()) {
            ans.push_back(sub);
        } else {
            for (size_t i = 0; i < nums.size(); ++i) {
                if (table[i] || nums[i] == nums[i - 1] && i > 0 && !table[i-1]) continue;
                sub.push_back(nums[i]);
                table[i] = true;
                backtrack(ans, nums, sub, table);
                sub.pop_back();
                table[i] = false;
            }
        }
    }
};
