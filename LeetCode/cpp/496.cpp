class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> _map;
        vector<int> ans(findNums.size(), -1);
        stack<int> _stack;
        for (size_t i = 0; i < findNums.size(); ++i) {
            _map[findNums[i]] = i;
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            while (!_stack.empty() && _stack.top() < nums[i]) {
                auto it = _map.find(_stack.top());
                if (it != _map.end()) {
                    ans[it->second] = nums[i];
                }
                _stack.pop();
            }
            _stack.push(nums[i]);
        }
        return ans;
    }
};
