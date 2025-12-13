class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        auto is_valid_code = [](const string& s) -> bool {
            if (s.empty()) return false;
            for (auto c : s)
                if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z') && !(c >= '0' && c <= '9') && !(c == '_')) return false;
            return true;
        };
        auto is_valid_businessLine = [](const string& s) -> bool {
            return (s == "electronics" || s == "grocery" || s == "pharmacy" || s == "restaurant");
        };
        int n = code.size();
        vector<int> ret;
        for (int i = 0;i < n; ++i) {
            if (is_valid_code(code[i]) && is_valid_businessLine(businessLine[i]) && isActive[i])
                ret.push_back(i);
        }
        sort(ret.begin(), ret.end(), [&](const int a, const int b) {
            if (businessLine[a] != businessLine[b])
                return businessLine[a] < businessLine[b];
            return code[a] < code[b];
        });
        vector<string> ans;
        for (int i : ret)
            ans.push_back(code[i]);
        return ans;
    }
};
