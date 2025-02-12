class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (const auto& str: strs)
        {
            string s(str);
            sort(s.begin(), s.end());
            anagrams[s].push_back(str);
        }
        vector<vector<string>> result;
        result.reserve(anagrams.size());
        for (const auto& [key, arr]: anagrams)
        {
            result.push_back(arr);
        }
        return result;
    }
};
