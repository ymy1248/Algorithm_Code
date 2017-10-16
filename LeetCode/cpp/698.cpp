class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        for (size_t i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        int avg = sum / k;
        if (sum % k != 0) {
            return false;
        }
        int *setSum = new int[k+1];
        for (size_t i = 0; i < k; ++i) {
            setSum[i] = 0;
        }
        setSum[k] = -1;
        stack<int *> _stack;
        _stack.push(setSum);
        
        while (!_stack.empty()) {
            int *node = _stack.top();
            _stack.pop();
            
            for (size_t i = 0; i < k; ++i) {
                int index = node[k] + 1;
                if (node[i] + nums[index] <= avg) {
                    int *next = new int[k+1];
                    for (size_t j = 0; j < k + 1; ++j) {
                        next[j] = node[j];
                    }
                    next[i] = node[i] + nums[index];
                    next[k]++;
                    if (next[k] == nums.size() - 1) {
                        return true;
                    }
                    // for (size_t j = 0; j < k + 1; ++j) {
                    //     cout << next[j] << " ";
                    // }
                    // cout << endl;
                    _stack.push(next);
                }
            }
            delete[] node;
        }
        return false;
    }
    
};
