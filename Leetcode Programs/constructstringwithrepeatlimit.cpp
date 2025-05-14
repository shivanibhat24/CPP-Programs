class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        string result;
        int i = 25, j = 24;
        while (i >= 0) {
            if (freq[i] == 0) {
                i--;
                continue;
            }
            int use = min(freq[i], repeatLimit);
            result.append(use, 'a' + i);
            freq[i] -= use;
            if (freq[i] > 0) {
                j = i - 1;
                while (j >= 0 && freq[j] == 0) j--;
                if (j < 0) break;
                result.push_back('a' + j);
                freq[j]--;
            }
        }
        return result;
    }
};
