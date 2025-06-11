class Solution {
public:
    string resultingString(string s) {
        vector<char> p;
        for (char c : s) {
            if (!p.empty() && (abs(p.back() - c) == 1 || abs(p.back() - c) == 25))
            {
                p.pop_back();
            } else {
                p.push_back(c);
            }
        }
        return string(p.begin(), p.end());
    }
};
