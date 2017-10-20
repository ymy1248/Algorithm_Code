class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        for (int i : nums) {
            map[i]++;
        }
        for (auto it : map) {
            pq.push({it.second, it.first});
            while (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        
        while (!pq.empty()) {
            ans.insert(ans.begin() ,pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

