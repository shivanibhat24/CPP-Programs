class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        int m = queries.size();
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; ++i) {
            nums.emplace_back(nums1[i], nums2[i]);
        }
        sort(nums.begin(), nums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        vector<pair<pair<int, int>, int>> sortedQueries;
        for (int i = 0; i < m; ++i) {
            sortedQueries.emplace_back(make_pair(queries[i][0], queries[i][1]), i);
        }
        sort(sortedQueries.begin(), sortedQueries.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
            return a.first.first > b.first.first;
        });        
        vector<int> ans(m);
        vector<pair<int, int>> mono; 
        int ptr = 0;
        for (int i = 0; i < m; ++i) {
            int x = sortedQueries[i].first.first;
            int y = sortedQueries[i].first.second;
            int idx = sortedQueries[i].second;
            while (ptr < n && nums[ptr].first >= x) {
                int current_y = nums[ptr].second;
                int sum = nums[ptr].first + nums[ptr].second;
                while (!mono.empty() && mono.back().second <= sum) {
                    mono.pop_back();
                }
                if (mono.empty() || mono.back().first < current_y) {
                    mono.emplace_back(current_y, sum);
                }
                ptr++;
            }
            auto it = lower_bound(mono.begin(), mono.end(), make_pair(y, 0));
            if (it != mono.end()) {
                ans[idx] = it->second;
            } else {
                ans[idx] = -1;
            }
        }        
        return ans;
    }
};
