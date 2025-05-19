class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size(), sz = s.size();
        vector<int> prefix(sz + 1, 0);
        for (int i = 0; i < n; i++) {
            int st = shifts[i][0], ed = shifts[i][1] ,dir = shifts[i][2];
            if (dir) {
                prefix[st]++;
                prefix[ed + 1]--;
            } else {
                prefix[st]--;
                prefix[ed + 1]++;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (i != 0) prefix[i] = ((prefix[i] + prefix[i - 1]) % 26 + 26) % 26;
            else    prefix[i] = (prefix[i] % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + prefix[i]) % 26;
        }
        return s;
    }
};
