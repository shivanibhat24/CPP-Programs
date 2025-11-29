class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for (char c : s)
        {
            cnt[c]++;
        }          
        vector<pair<int, char>> v;
        for (auto &p : cnt)
        {
            v.push_back({p.second, p.first});
        }
        sort(v.rbegin(), v.rend());
        string ans = "";
        for (auto &p : v)
        {
            for (int i=0; i<p.first; ++i) ans.push_back(p.second);
        }
        return ans;
    }
};
