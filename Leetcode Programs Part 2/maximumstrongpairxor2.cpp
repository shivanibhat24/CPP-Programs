class Solution {
public:
    constexpr int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int width = bit_width(static_cast<unsigned int>(nums.back()));
        bool buf[(1 << (width + 1)) - 1];
        memset(buf, 0, sizeof buf);
        for (int num : nums) {
            int curr = 0;
            for (int i = width - 1; i >= 0; i--) {
                if (!buf[2 * curr + 1 + ((num >> i) & 1)]) {
                    buf[2 * curr + 1 + ((num >> i) & 1)] = true;
                }
                curr = 2 * curr + 1 + ((num >> i) & 1);
            }
        }
        int ret = 0;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            int num = *it;
            int upper = *prev(upper_bound(next(it), nums.end(), 2 * num));
            int tmp = 0;
            int curr = 0;
            int i = width - 1;
            bool check_lower = true;
            bool check_upper = true;
            for (int i = width - 1; i >= 0; i--) {
                if ((num >> i) & 1) {
                    if (check_lower || !buf[2 * curr + 1]) {
                        curr = 2 * curr + 2;
                    } else {
                        if ((upper >> i) & 1) {
                            check_upper = false;
                        }
                        curr = 2 * curr + 1;
                        tmp |= 1 << i;
                    }
                } else {
                    if (check_upper) {
                        if ((upper >> i) & 1) {
                            check_lower = false;
                            curr = 2 * curr + 2;
                            tmp |= 1 << i;
                        } else {
                            curr = 2 * curr + 1;
                        }
                    } else if (buf[2 * curr + 2]) {
                        check_lower = false;
                        curr = 2 * curr + 2;
                        tmp |= 1 << i;
                    } else {
                        curr = 2 * curr + 1;
                    }
                }
            }
            if (tmp > ret) {
                ret = tmp;
            }
        }
        return ret;
    }
};
