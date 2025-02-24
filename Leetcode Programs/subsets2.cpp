class Solution {
public:
    void solve(vector<int> &nums, vector<int> &temp, map<vector<int>, int> &track, vector<vector<int>> &ans, int index) {
        if (track.find(temp) == track.end()) {
            track[temp]++;
            ans.push_back(temp);
        }
        if (index == nums.size()) {
            return;
        }
        temp.push_back(nums[index]);
        solve(nums, temp, track, ans, index + 1);
        temp.pop_back();
        solve(nums, temp, track, ans, index + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0;
        map<vector<int>, int> track;
        sort(nums.begin(), nums.end());
        solve(nums, temp, track, ans, index);

        return ans;
    }
};
