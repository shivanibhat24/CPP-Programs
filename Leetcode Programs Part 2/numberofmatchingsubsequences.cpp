class Solution {
public:
    int numMatchingSubseq(string_view s, const vector<string>& words) {
        array<vector<int>, 26> idx;
        for (int i = 0; i < (int)s.size(); ++i)
            idx[s[i] - 'a'].push_back(i);
        int ans = 0;
        for (const string& w : words) {
            int pos = -1;
            bool ok = true;
            for (char ch : w) {
                const auto& vec = idx[ch - 'a'];
                auto it = lower_bound(vec.begin(), vec.end(), pos + 1);
                if (it == vec.end()) { ok = false; break; }
                pos = *it;
            }
            ans += ok;
        }
        return ans;
    }
};
