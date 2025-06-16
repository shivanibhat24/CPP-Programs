class Solution {
    static int bits(char c) {
        switch(c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
        return 0;
    }
    static int update(int key, char c) {
        return ((key & 0b111111111111111111) << 2) | bits(c);
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>result;
        if (s.size() < 11) return result;
        int key = 0;
        char seen[1<<20]{};
        for (int i = 0; i < 10; i++) {
            key = update(key, s[i]);
        }
        seen[key] = 1;
        for (int i = 10; i < s.size(); ++i) {
            key = update(key, s[i]);
            if (seen[key] == 1) {
                seen[key] = 2;
                result.push_back(s.substr(i - 9, 10));
            } else if (seen[key] == 0) {
                seen[key] = 1;
            }
        }
        return result;
    }
};
