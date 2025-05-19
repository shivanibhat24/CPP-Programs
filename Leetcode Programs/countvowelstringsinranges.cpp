class Solution {
public:
    inline bool isVowel(const char& c) {
        switch(c) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                return true;
            default:
                return false;
        }
    }
    inline int isVowelWord(const string& word){
        if (word.empty()) {
            return 0;
        }
        return isVowel(word[0]) && isVowel(word.back());
    }
    vector<int> vowelStrings(const vector<string>& words, vector<vector<int>>& queries) {
        vector<int> pref(words.size() + 1), result(queries.size());
        for (size_t i = 1, len = pref.size(); i < len; ++i) {
            pref[i] += pref[i - 1] + isVowelWord(words[i - 1]);
        }
        for (size_t i = 0, len = result.size(); i < len; ++i) {
            const int &l = queries[i][0], &r = queries[i][1];
            result[i] = pref[r + 1] - pref[l];
        }
        return result;
    }
};
