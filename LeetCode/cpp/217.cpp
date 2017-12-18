class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> _set;
        for(size_t i = 0; i < nums.size(); ++i) {
            if (_set.find(nums[i]) != _set.end()) {
                return true;
            }
            _set.insert(nums[i]);
        }
        return false;
    }
};
