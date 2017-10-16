class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> max;
        unordered_map<int, int> min;
        unordered_map<int, int> fre;
        vector<int> n;
        int maxFre = -1;
        
        for (size_t i = 0; i < nums.size(); ++i) {
            auto it = fre.find(nums[i]);
            if (it == fre.end()) {
                fre[nums[i]] = 1;
            } else {
                fre[nums[i]] = it->second + 1;
            }
            if (fre[nums[i]] == 1) {
                min[nums[i]] = i;
            } else {
                max[nums[i]] = i;
            }
            
            if (fre[nums[i]] > maxFre) {
                n.clear();
                n.push_back(nums[i]);
                maxFre = fre[nums[i]];
            } else if (fre[nums[i]] == maxFre) {
                n.push_back(nums[i]);
            }
        }
        if (maxFre == 1) {
            return 1;
        }
        
        int len = INT_MAX;
        for (size_t i = 0; i < n.size(); ++i) {
            int l = max[n[i]] - min[n[i]];
            len = len < l ? len : l;
        }
        return len + 1;
    }
};
