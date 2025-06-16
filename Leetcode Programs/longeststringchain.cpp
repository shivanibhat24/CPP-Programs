class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        unordered_map<string, int> chains;
        int res = 0;
        for (const string& word : words) {
            chains[word] = 1;
            for (int i = 0; i < word.size(); ++i) {
                string pred = word.substr(0, i) + word.substr(i + 1);
                if (chains.count(pred)) {
                    chains[word] = max(chains[word], chains[pred] + 1);
                }
            }
            res = max(res, chains[word]);
        }
        return res;
    }
};
