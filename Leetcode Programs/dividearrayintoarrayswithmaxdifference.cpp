class Solution {
public:
    vector<vector<int>> divideArray(const vector<int>& nums, int k) {
        const int max = *std::max_element(cbegin(nums), cend(nums));
        std::vector<int> frequencies(max + 1, 0);
        for (int val : nums) {
            ++frequencies[val];
        }
        constexpr int N_SUB_ARRAY = 3;
        const int num_subarrays = nums.size() / N_SUB_ARRAY;
        vector<vector<int>> result;
        result.reserve(num_subarrays);
        int bucket = 0;
        vector<int> sub(3);                
        int sub_index = 0;
        for (int bucket = 0; bucket <= max; ++bucket) {
            while (frequencies[bucket]-- > 0) {
              
                sub[sub_index++] = bucket;
                if (sub_index == 3) {
                    if (sub[2] - sub[0] > k) {
                        return {};
                    } else {
                        result.emplace_back(sub);
                        
                        sub_index = 0;
                    }
                }
            }
        }
        return result;
    }
};
