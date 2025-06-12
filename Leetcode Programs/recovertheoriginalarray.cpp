class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res(n / 2, 0);
        for (int i = 1; i < n; i++) {
            int k = nums[i] - nums[0];
            if (k == 0 || k % 2 == 1) {
                continue;
            }
            k = k / 2;
            int low = 0;
            int high = 0;
            res[low] = nums[0] + k;
            low += 1;
            for (int j = 1; j < n; j++) {
                if (high < low && nums[j] - k == res[high]) {
                    high += 1;
                } else if (low < res.size()) {
                    res[low] = nums[j] + k;
                    low += 1;
                } else {
                    break;
                }
            }
            if (low == res.size() && high == res.size()) {
                break;
            }
        }
        return res;
    }
};
