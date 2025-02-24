class Solution {
public:
    using int2 = pair<int, int>;
    vector<int2> bucket[64];
    void radix_sort(vector<int2>& nums, int xmin, int xmax) {
        unsigned xrange = xmax - xmin + 1;
        int round = max(1, int(32 - countl_zero(xrange) + 5) / 6);

        // 0th round
        for (auto& [x, idx] : nums) {
            x -= xmin; // Adjust x by xmin
            bucket[x & 63].emplace_back(x+=(round==1)?xmin:0, idx);
        }

        int i = 0;
        for (auto& B : bucket) {
            for (auto& v : B)
                nums[i++] = v;
            B.clear(); // Clear bucket after usage
        }
        //    print(nums);

        // Rounds from 1st to (round-2)th round
        for (int rd = 1; rd < round - 1; rd++) {
            int shift =
                rd * 6; // Bit shifting to extract the next set of 6 bits
            for (auto& [x, idx] : nums)
                bucket[(x >> shift) & 63].emplace_back(x, idx);

            i = 0;
            for (auto& B : bucket) {
                for (auto& v : B)
                    nums[i++] = v;
                B.clear(); // Clear bucket after usage
            }
            //    print(nums);
        }

        // Last round
        if (round > 1) {
            int shift = 6 * (round - 1); // Bit shifting for the last round
            for (auto& [x, idx] : nums)
                bucket[x >> shift].emplace_back(x, idx);

            i = 0;
            for (auto& B : bucket) {
                for (auto& [x, idx] : B)
                    nums[i++] = {x + xmin, idx}; // Adjust x back by adding xmin
                B.clear();                       // Clear bucket after usage
            }
            //    print(nums);
        }
    }

    vector<int> arrayRankTransform(vector<int>& arr) {
        const int n = arr.size();
        // Initialize arrIdx with values and original indices
        if (n==0) return {};
        
        vector<int2> arrIdx(n);
        for (int i = 0; i < n; i++)
            arrIdx[i] = {arr[i], i}; // Store value and original index

        // Find the minimum and maximum
        auto [xmin, xmax] = minmax_element(arr.begin(), arr.end());
        radix_sort(arrIdx, int(*xmin), int(*xmax)); // Perform radix sort

        // Rank transformation with handling duplicates
        vector<int> ans(n);
        int prev = INT_MIN, curr = 0;
        for (auto& [x, i] : arrIdx) {
            if (x > prev)
                curr++;
            ans[i] = curr;
            prev = x;
        }
        return ans;
    }
};
