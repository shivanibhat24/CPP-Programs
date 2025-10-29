bool check(std::vector<std::vector<int>> const & lcp, std::string const & s) {
    int n = int(lcp.size());
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= i; j--) {
            // [i, j]
            if (i == j && (lcp[i][i] != (n - i))) return false;
            if (lcp[i][j] != lcp[j][i]) return false;
            if (lcp[i][j] == 0) {
                if (s[i] == s[j]) return false;
                continue;
            } else {
                if (s[i] != s[j]) return false;
                if (i == n - 1 || j == n - 1) {
                    if (lcp[i][j] > 1) return false;
                } else {
                    if (lcp[i + 1][j + 1] + 1 != lcp[i][j]) return false;
                }
            }
            
        }
    }
    
    return true;
}

std::string solve(std::vector<std::vector<int>> const & lcp) {
    int n = int(lcp.size());
    std::string ans = "a";
    ans.reserve(n);
    char curr = 'b';
    
    for (int i = 1; i < n; i++) {
        bool find = false;
        for (int j = 0; j < i; j++) {
            if (lcp[j][i] == 0) continue;
            ans += ans[j];
            find = true;
            break;
        }
        if (!find) {
            ans += curr;
            if (curr > 'z') return "";
            curr++;
            
        }
    }
    if (check(lcp, ans)) {
        return ans;
    }
    return "";

}

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        return solve(lcp);
    }
};
