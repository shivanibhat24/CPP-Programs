class Solution {
public:
    __attribute__((hot)) vector<string> solve(string s, int i, int j) {
        vector<string> ans;
        for (int d = 1; d <= j - i; d++) {
            string left = s.substr(i, d), right = s.substr(i + d, j - i - d);
            if ((left[0] != '0' || left == "0") && (right.empty() || right.back() != '0')) {
                ans.push_back(left + (d < j - i ? "." : "") + right);
            }
        }
        return ans;
    }
    __attribute__((hot)) vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        for (int i = 2; i < s.length() - 1; i++) {
            vector<string> left = solve(s, 1, i);
            vector<string> right = solve(s, i, s.length() - 1);
            for (const string &s1 : left) {
                for (const string &s2 : right) {
                    ans.push_back("(" + s1 + ", " + s2 + ")");
                }
            }
        }
        return ans;
    }
};
