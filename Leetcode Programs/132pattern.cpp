class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        vector<int> MIN(n);
        MIN[0] = nums[0];
        for (int i=1; i<n; ++i) MIN[i] = std::min(MIN[i-1],nums[i]);
        for (int j=n-1, k = n; j>0; --j) {
            if (nums[j] <= MIN[j]) continue;
            while (k<n && nums[k] <= MIN[j]) ++k;
            if (k<n && nums[k] < nums[j]) return true;
            nums[--k] = nums[j];
        }
        return false;
    }
};
