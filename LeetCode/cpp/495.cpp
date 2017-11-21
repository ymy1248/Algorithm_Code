class Solution {
public:
    int findPoisonedDuration(vector<int>& time, int duration) {
        if (time.size() == 0 || duration == 0) {
            return 0;
        }
        unsigned int end = time[time.size() - 1] + duration - 1;
        int ans = 0;
        int index = 0;
        int active = 0;
        // cout << end << endl;
        for (unsigned int i = 0; i <= end; ++i) {
            if (index < time.size() && i == time[index]) {
                active = duration - 1;
                ++ans;
                // cout << ans << endl;
                // cout << i << endl;
                ++index;
                while (index + 1 < time.size() && time[index] == time[index + 1]) {
                    // cout << index << ", ";
                    index++;
                }
            } else {
                if (active > 0) {
                    --active;
                    ++ans;
                    // cout << ans << endl;
                    // cout << i << endl;
                }
            }
        }
        // cout << index << endl;
        // cout << time[index] << endl;
        return ans;
    }
};
