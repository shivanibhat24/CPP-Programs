class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) 
    {
        int n = events.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) 
        {
            v[i].first = events[i][0];
            v[i].second = events[i][2];
        }
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) 
        {
            if (a.first != b.first)
            {
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        vector<int> suffixMax(n);
        suffixMax[n - 1] = v[n - 1].second;
        for (int i = n - 2; i >= 0; i--) 
        {
            suffixMax[i] = max(v[i].second, suffixMax[i + 1]);
        }
        int maxi = 0;
        for (int i = 0; i < n; i++) 
        {
            int endTime = events[i][1];
            int reward = events[i][2];
            auto it = upper_bound(v.begin(), v.end(), make_pair(endTime, INT_MAX));
            if (it != v.end()) 
            {
                int idx = it - v.begin();
                maxi = max(maxi, reward + suffixMax[idx]);
            }
            maxi = max(maxi, reward);
        }
        return maxi;
    }
};
