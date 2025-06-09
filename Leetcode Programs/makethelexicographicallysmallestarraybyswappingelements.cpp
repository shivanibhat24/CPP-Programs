class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> map;
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.push_back({nums[i], i});
            map.push_back(0);
        }
        sort(pairs.begin(), pairs.end(), [&](auto& a, auto& b) { return a.first < b.first; });
        vector<pair<int, int>> sets = {{n - 1, n - 1}};
        for (int i = n - 2, group = 0; i >= 0; i--) {
            if (pairs[i + 1].first - pairs[i].first <= limit) {
                sets.back().first = i;
            } 
            else {
                sets.push_back({i, i});
                ++group;
            }
            map[pairs[i].second] = group;
        }
        for (int i = 0; i < n; i++) {
            nums[i] = pairs[sets[map[i]].first++].first;
        }
        return nums;
    }
};
