class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minimal = INT_MAX;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < nums.size(); k++){
            int subT = target - nums[k];
            int i = 0==k? 1:0;
            int j = nums.size()-1 == k? nums.size()-2: nums.size()-1;
            while(i < j){
                int sum = nums[i] + nums[j];
                if(abs(target - sum - nums[k]) < minimal){
                    ans = sum + nums[k];
                    minimal = abs(target - sum - nums[k]);
                }
                if(subT - sum > 0){
                    i = ++i==k?++i:i;
                } else if(subT - sum < 0){
                    j = --j==k?--j:j;
                } else{
                    // cout << "I am here" << endl;
                    return target;
                }
            }
        }
        return ans;
    }
};
