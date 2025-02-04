class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m > n) return -1;
        if (m == 0) return 0;
        const int base = 31;  // Prime base for hashing
        const int mod = 1e9 + 7; long long needleHash = 0, hayHash = 0, power = 1;
        for (int i = 0; i < m; i++) {
            needleHash = (needleHash * base + needle[i]) % mod;
            hayHash = (hayHash * base + haystack[i]) % mod;
            power = (power * base) % mod;  // Precompute base^(m-1)
        }
        if (hayHash == needleHash && haystack.substr(0, m) == needle)
            return 0;
        for (int i = m; i < n; i++) {
            hayHash = (hayHash * base + haystack[i] - haystack[i - m] * power % mod + mod) % mod;
            if (hayHash == needleHash && haystack.substr(i - m + 1, m) == needle)
                return i - m + 1;
        }
        return -1;
    }
};
