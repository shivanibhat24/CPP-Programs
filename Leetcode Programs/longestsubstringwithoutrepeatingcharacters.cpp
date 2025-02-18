class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          const int n = static_cast<int>(s.size());
        if (n <= 1) return n;
        uint64_t used[4] = {0, 0, 0, 0};
        auto isUsed = [&](unsigned char c) {
            return (used[c >> 6] & (1ULL << (c & 63))) != 0;
        };
        auto setUsed = [&](unsigned char c) {
            used[c >> 6] |= (1ULL << (c & 63));
        };
        auto clearUsed = [&](unsigned char c) {
            used[c >> 6] &= ~(1ULL << (c & 63));
        };
        int left = 0, maxLen = 0;
        for (int right = 0; right < n; ++right) {
            unsigned char rc = static_cast<unsigned char>(s[right]);
            while (isUsed(rc)) {
                unsigned char lc = static_cast<unsigned char>(s[left]);
                clearUsed(lc);
                ++left;
            }
            setUsed(rc);
            int currLen = right - left + 1;
            if (currLen > maxLen) {
                maxLen = currLen;
            }
        }
        return maxLen;
    }
};
