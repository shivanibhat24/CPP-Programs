#include <algorithm>
#include <ranges>
#include <vector>
class Solution {
public:
    long long maximizeXorAndXor(vector<int>& nums) {
        int n = nums.size();
        static int MAX_ELEMENTS = 19;
        static int MAX_MASK = (1 << MAX_ELEMENTS) - 1;
        int total_mask = (1 << n) - 1;
        auto initial = std::chrono::system_clock::now();
        if(std::all_of(nums.begin(), nums.end(), 
            [&nums](const int x){ return x == nums[0]; })){
            return static_cast<long long>(nums[0])*std::min(n, 3);
        }
        static std::vector<unsigned int> xor_dp(MAX_MASK + 1, 0);
        std::fill(xor_dp.begin(), xor_dp.begin() + total_mask + 1, 0);
        static std::vector<unsigned int> and_dp(MAX_MASK + 1, ~0U);
        std::fill(and_dp.begin(), and_dp.begin() + total_mask + 1, ~0U);
        for (int mask = 1; mask <= total_mask; ++mask) {
            int i = __builtin_ctz(mask);        
            int prev = mask ^ (1 << i);
            xor_dp[mask] = xor_dp[prev] ^ nums[i];
            and_dp[mask] = and_dp[prev] & nums[i];
        }
        and_dp[0] = 0;
        auto xor_precompute = std::chrono::system_clock::now();
        static std::vector<unsigned int> max_xor_dp(MAX_MASK + 1, 0);
        std::copy(xor_dp.begin(), xor_dp.begin() + total_mask + 1, max_xor_dp.begin());
        for(int i = 0; i < n; ++i){
            for(int mask = 0; mask <= total_mask; ++mask){
                if(mask & (1 << i)){
                    max_xor_dp[mask] = 
                        std::max(max_xor_dp[mask], max_xor_dp[mask ^ (1 << i)]);
                }
            }
        }
        using std::chrono::system_clock;
        using std::chrono::milliseconds;
        using std::chrono::duration_cast;
        auto max_xor_precompute = system_clock::now();
        auto later = std::chrono::system_clock::now();
        unsigned int largest_xor_sum = 0;
        for(int mask = 0; mask <= total_mask; ++mask){
            unsigned int val = xor_dp[mask] + max_xor_dp[total_mask ^ mask];
            largest_xor_sum = std::max(largest_xor_sum, val);
        }
        auto largest_xor = system_clock::now();
        auto now_again = std::chrono::system_clock::now();
        unsigned int best = largest_xor_sum;
        unsigned int baseline = largest_xor_sum;
        unsigned int skip = 0;
        for (int b_mask = 0; b_mask <= total_mask; ++b_mask) {
            unsigned int and_val = and_dp[b_mask];
            if(and_val <= skip){
                continue;
            }
            int rem = total_mask ^ b_mask; 
            unsigned int tprime = xor_dp[rem];
            for(int subset = rem; ; subset = (subset - 1) & rem){
                unsigned int xor_A = xor_dp[subset];
                unsigned int possible = tprime + ((xor_A & ~tprime) << 1) + and_val;
                if(possible > best){
                    best = possible;
                    skip = possible - baseline;
                }
                if(subset == 0){
                    break;
                }
            }
        }
        auto later_again = std::chrono::system_clock::now();
        return best;
    }
};
