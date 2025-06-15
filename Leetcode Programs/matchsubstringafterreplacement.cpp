class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n = s.size();
        int m = sub.size();
        bool mapTable[256][256] = {false};
        for (const auto& mapping : mappings) {
            mapTable[(unsigned char)mapping[0]][(unsigned char)mapping[1]] = true;
        }
        for (int start = 0; start <= n - m; start++) {
            bool valid = true;
            for (int j = 0; j < m; j++) {
                char subChar = sub[j];
                char sChar = s[start + j];
                if (subChar == sChar)
                    continue;
                if (!mapTable[(unsigned char)subChar][(unsigned char)sChar]) {
                    valid = false;
                    break;
                }
            }
            if (valid) return true;
        }
        return false;
    }
};
int ddddddd(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, sub;
    cin >> s >> sub;
    int k;
    cin >> k;
    vector<vector<char>> mappings(k, vector<char>(2));
    for (int i = 0; i < k; i++){
        cin >> mappings[i][0] >> mappings[i][1];
    }    
    Solution solution;
    bool result = solution.matchReplacement(s, sub, mappings);
    cout << (result ? "true" : "false") << "\n";
    return 0;
}
