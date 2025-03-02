class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::vector<std::vector<int>> ans;
        std::vector<int> v1, v2;
        std::bitset<2001> bits1 = 0, bits2 = 0;
        for (auto& i : nums1) bits1[i+1000] = 1;
        for (auto& i : nums2) bits2[i+1000] = 1;

        for (int i = 0; i < 2001; ++i) {
            if (bits1[i] != bits2[i]) {
                if (bits1[i]) v1.push_back(i-1000);
                else v2.push_back(i-1000);
            }
        }

        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};
