class Solution {
public:
int maxDistance(string s, int k) {
    int res = 1, hor = 0, ver = 0;
    for (int i = 0; i < s.size(); ++i) {
        ver += s[i] == 'N' ? 1 : s[i] == 'S' ? -1 : 0;
        hor += s[i] == 'W' ? 1 : s[i] == 'E' ? -1 : 0;
        res = max(res, min(abs(hor) + abs(ver) + 2 * k, i + 1));
    }
    return res;
}
};
