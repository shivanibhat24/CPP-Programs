class Solution {
public:
    string maskPII(string s) {
        const int len = s.length();
        auto pos = s.find('@');
        if (pos != string::npos) {
            string res;
            res.reserve(len + 5);
            res.push_back(tolower(s[0]));
            res += "*****";
            res.push_back(tolower(s[pos - 1]));
            for (int i = pos; i < len; ++i) res.push_back(tolower(s[i]));
            return res;
        }
        string digits;
        digits.reserve(16);
        for(int i = 0; i < len; ++i){
            if(isdigit(s[i])) digits.push_back(tolower(s[i]));
        }
        int n = digits.size();
        string res;
        res.reserve(20);
        if (n > 10) {
            res.push_back('+');
            res.append(n - 10, '*');
            res.push_back('-');
        }
        res += "***-***-";
        res.append(digits.end() - 4, digits.end());
        return res;
    }
};
