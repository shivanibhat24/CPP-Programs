class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;        
        res.reserve(n + 1);
        res.push_back(0);
        for (int i = 1; i <= n; ++i) {

                res.push_back(res[ i / 2] + (i & 1));
        }
        return res;
    }
};
