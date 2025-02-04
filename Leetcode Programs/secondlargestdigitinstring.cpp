class Solution {
public:
    int secondHighest(string s) {
        int res = -1, prev_res = -1;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                int num = s[i] - '0';
                if (num > res) {
                    prev_res = res;
                    res = num;
                } else if (num > prev_res && num < res) {
                    prev_res = num;
                }
            }
        }
        return prev_res;
    }
};
