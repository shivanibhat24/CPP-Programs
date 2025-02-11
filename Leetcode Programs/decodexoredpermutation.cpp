class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int xorAllButFirst = encoded[1];
        for (int i = 3; i < encoded.size(); i += 2) {
            xorAllButFirst ^= encoded[i];
        }
        int totalXor = 1;
        int n = encoded.size() + 1;
        for (int i = 2; i <= n; i++) {
            totalXor ^= i;
        }
        int prev = totalXor ^ xorAllButFirst;
        vector<int> res(n);
        res[0] = prev;
        for (int i = 1; i < n; i++) {
            res[i] = prev ^ encoded[i-1];
            prev = res[i];
        }
        return res;
    }
};
