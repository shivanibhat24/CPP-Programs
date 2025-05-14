class Solution {
    const int W = 59;
    unsigned int hash(const string &s) {
        unsigned int r = 0;
        for (char c : s) {
            r = r * W + c;
        }
        return r;
    }
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<unsigned int> banned;
        for (const auto& s : bannedWords) {
           banned.insert(hash(s));
        }
        int r = 0;
        for (const auto& s : message) {
            if ((r += banned.count(hash(s))) == 2) return true;
        }
        return false;
    }
};
