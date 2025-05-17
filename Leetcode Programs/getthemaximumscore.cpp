class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        auto ptr1 = nums1.begin();
        auto ptr2 = nums2.begin();
        const int64_t kModulo = 1000000007;
        int64_t max_sum = 0;
        int64_t sum1 = 0;
        int64_t sum2 = 0;
        while ((ptr1 != nums1.end()) && (ptr2 != nums2.end())) {
            if (*ptr1 == *ptr2) {
                max_sum += std::max(sum1, sum2);
                max_sum += static_cast<int64_t>(*ptr1);
                sum1 = 0;
                sum2 = 0;
                ++ptr1;
                ++ptr2;
            } else if (*ptr1 < *ptr2) {
                sum1 += *ptr1;
                ++ptr1;
            } else {
                sum2 += *ptr2;
                ++ptr2;
            }
        }
        if (ptr1 == nums1.end()) {
            while (ptr2 != nums2.end()) {
                sum2 += *ptr2;
                ++ptr2;
            }
        } else {
            while (ptr1 != nums1.end()) {
                sum1 += *ptr1;
                ++ptr1;
            }
        }
        max_sum += std::max(sum1, sum2);
        return static_cast<int>(max_sum % kModulo);
    }
};
