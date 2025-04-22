class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> lastRain; 
        deque<int> zeroDays;
        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                zeroDays.push_back(i);
                ans[i] = 1;
            } else {
                int lake = rains[i];
                if (lastRain.find(lake) != lastRain.end()) {
                    auto it = lower_bound(zeroDays.begin(), zeroDays.end(), lastRain[lake]);
                    if (it == zeroDays.end()) {
                        return {}; 
                    }
                    int zeroDay = *it;
                    ans[zeroDay] = lake;
                    zeroDays.erase(it);
                }
                lastRain[lake] = i;
                ans[i] = -1;
            }
        }
        return ans;
    }
};
