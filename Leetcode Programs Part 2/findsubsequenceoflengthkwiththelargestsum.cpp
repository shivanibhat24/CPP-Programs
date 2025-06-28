class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> ind;
    for (int i = 0; i < nums.size(); i++) {
        ind.push_back({nums[i], i});
    }
    sort(ind.begin(), ind.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first; 
    });
    ind.resize(k);
    sort(ind.begin(), ind.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second; 
    });
    vector<int> result;
    for (auto& p : ind) {
        result.push_back(p.first);
    }
    return result;        
    }
};
