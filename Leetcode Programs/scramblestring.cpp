class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        static char dp[31][31][31] = {0}; 
        memset(dp, 0, sizeof(dp));        
        return isScrambleHelper(s1.c_str(), s2.c_str(), 0, 0, n, dp);
    }    
private:
    bool isScrambleHelper(const char* s1, const char* s2, 
                         int start1, int start2, int len, 
                         char dp[31][31][31]) {
        if (dp[start1][start2][len] != 0) {
            return dp[start1][start2][len] == 1;
        }
        if (len == 1) {
            bool result = (s1[start1] == s2[start2]);
            dp[start1][start2][len] = result ? 1 : 2;
            return result;
        }
        int freq = 0; 
        for (int i = 0; i < len; i++) {
            freq += 1 << (s1[start1 + i] - 'a');
            freq -= 1 << (s2[start2 + i] - 'a');
        }
        if (freq != 0) {
            dp[start1][start2][len] = 2;
            return false;
        }
        for (int i = 1; i < len; i++) {
            if (isScrambleHelper(s1, s2, start1, start2, i, dp) &&
                isScrambleHelper(s1, s2, start1 + i, start2 + i, len - i, dp)) {
                dp[start1][start2][len] = 1;
                return true;
            }
            if (isScrambleHelper(s1, s2, start1, start2 + len - i, i, dp) &&
                isScrambleHelper(s1, s2, start1 + i, start2, len - i, dp)) {
                dp[start1][start2][len] = 1;
                return true;
            }
        }        
        dp[start1][start2][len] = 2;
        return false;
    }
};
