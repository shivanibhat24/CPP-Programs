class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> parts;
        string curr;
        for (int i = 1; i < n; i++) {
            if (path[i] == '/') {
                if (path[i - 1] != '/') {
                    parts.push_back(curr);
                    curr = "";
                }
            } else {
                curr += path[i];
            }
        }
        if (curr != "") {
            parts.push_back(curr);
        }
        vector<string> ans;
        for (auto x : parts) {
            if (x == ".")
                continue;
            else if (x == "..") {
                if (!ans.empty())
                    ans.pop_back();
            } else
                ans.push_back(x);
        }
        string fans = "";
        for (auto x : ans) {
            fans += '/';
            fans += x;
        }
        if (fans == "") fans = "/";
        return fans;
    }
};
