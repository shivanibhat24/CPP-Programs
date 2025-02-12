class Solution {
    const int MOD = 1e9 + 7;
    int mul(int a, int b) { return (int)(1LL * a * b % MOD); }
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        int base = 29;
        long long cnt = 0;
        unordered_map<int, long long> seen;
        for (int i = 0; i < words.size(); i++) {
            long long prefix = 0, suffix = 0, p = 1;
            for (int j = 0; j < words[i].size(); j++) {
                prefix += mul(words[i][j] - 'a' + 1, p);
                if (prefix >= MOD) prefix -= MOD;
                suffix = mul(suffix, base);
                suffix += words[i][words[i].size() - 1 - j] - 'a' + 1;
                if (suffix >= MOD) suffix -= MOD;
                if (prefix == suffix && seen.count(prefix)) {
                    cnt += seen[prefix];
                }
                p = mul(p, base);
            }
            seen[prefix]++;
        }
        return cnt;
    }
};
