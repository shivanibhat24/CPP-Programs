class Solution {
public:
    const long long MOD = 1000000007;
    long long modExp(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while(exp > 0) {
            if(exp & 1)
                res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }    
    int countAnagrams(string s) {
        vector<string> words;
        int n = s.size(), start = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                words.push_back(s.substr(start, i - start));
                start = i + 1;
            }
        }
        words.push_back(s.substr(start));
        int maxLen = 0;
        for (const auto &w : words) {
            maxLen = max(maxLen, (int)w.size());
        }
        vector<long long> fact(maxLen + 1, 1), invFact(maxLen + 1, 1);
        for (int i = 1; i <= maxLen; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[maxLen] = modExp(fact[maxLen], MOD - 2, MOD);
        for (int i = maxLen - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }        
        long long result = 1;
        for (const auto &w : words) {
            int lenW = w.size();
            long long ways = fact[lenW];
            int freq[26] = {0};
            for (char c : w) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) {
                    ways = (ways * invFact[freq[i]]) % MOD;
                }
            }
            result = (result * ways) % MOD;
        }        
        return (int)result;
    }
};
