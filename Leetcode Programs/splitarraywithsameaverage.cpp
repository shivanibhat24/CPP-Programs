class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        const uint32_t n = nums.size();
        if (n <= 1) return false;
        if (n == 2) return nums[0] == nums[1];
        uint32_t sum = 0;
        for (const int& num : nums) sum += num;
        bool possible = false;
        const uint32_t half = n >> 1;
        for (uint32_t i = 1; i <= half && !possible; ++i) {
            if ((sum * i) % n == 0) possible = true;
        }
        if (!possible) return false;
        for (int& num : nums) {
            num = num * n - sum;
        }
        const uint32_t m = n >> 1;
        vector<uint64_t> bits(10001, 0); 
        for (uint32_t mask = 1; mask < (1u << m); ++mask) {
            int subset_sum = 0;
            uint32_t tmp_mask = mask;
            while (tmp_mask) {
                const uint32_t idx = __builtin_ctz(tmp_mask);
                subset_sum += nums[idx];
                tmp_mask &= tmp_mask - 1;
            }
            if (!subset_sum) return true;            
            const uint32_t idx = (subset_sum + 50000) >> 6;
            if (idx < bits.size()) {
                bits[idx] |= 1ULL << ((subset_sum + 50000) & 63);
            }
        }
        int rsum = 0;
        for (uint32_t i = m; i < n; ++i) rsum += nums[i];
        for (uint32_t mask = 1; mask < (1u << (n - m)); ++mask) {
            int subset_sum = 0;
            uint32_t tmp_mask = mask;
            while (tmp_mask) {
                const uint32_t idx = __builtin_ctz(tmp_mask);
                subset_sum += nums[m + idx];
                tmp_mask &= tmp_mask - 1;
            }            
            if (!subset_sum) return true;
            const uint32_t check_idx = (-subset_sum + 50000) >> 6;
            if (check_idx < bits.size() && 
                subset_sum != rsum && 
                (bits[check_idx] & (1ULL << ((-subset_sum + 50000) & 63)))) {
                return true;
            }
        }        
        return false;
    }
};
