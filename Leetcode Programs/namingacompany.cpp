class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string, bitset<26>> mp;
        for (const string& s : ideas) mp[s.substr(1)].set(s[0] - 'a');
        long long dp[26][26] = {0}, ret = 0, i, j;
        for (auto [_, b] : mp) for (i = 26; i--;) if (b[i]) for (j = 26; j--;) if (!b[j]) ++dp[i][j], ret += dp[j][i];
        return 2 * ret;
    }
};
