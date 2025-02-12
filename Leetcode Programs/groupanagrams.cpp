class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<int, int>> mapping;
        for (int i = 0; i < strs.size(); ++i) {
            uint hash = 0, counts[26] {0};
            for (const auto& ch: strs[i]) ++counts[ch - 'a'];
            for (int j = 0; j < 26; ++j) hash *= 31, hash ^= counts[j];
            mapping.emplace_back(hash, i); 
        }
        ranges::sort(mapping);
        vector<vector<string>> res;
        res.push_back({move(strs[mapping[0].second])});
        for (int i = 1; i < mapping.size(); ++i) {
            if (mapping[i].first == mapping[i - 1].first)
                res.back().emplace_back(move(strs[mapping[i].second]));
            else
                res.push_back({move(strs[mapping[i].second])});
        }
        return res; 
    }
};
