class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {        
        int max_val = INT_MIN;
        int min_val = INT_MAX;
        for(const auto n : nums) {
            max_val = max(max_val, n);
            min_val = min(min_val, n);
        }
        std::vector<int> count(max_val - min_val + 1, 0);
        for(const auto n : nums) {
            count[n - min_val]++;
        }
        for(int idx = max_val - min_val; idx >= 0; idx--) {
            k -= count[idx];
            if(k <= 0) {
                return idx + min_val;
            }
        }
        return -1;
    }
};
