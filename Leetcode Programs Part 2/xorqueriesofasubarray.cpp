class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        vector<int> result;
        for (auto& q : queries) {
            int L = q[0], R = q[1];
            result.push_back(prefix[R + 1] ^ prefix[L]);
        }
        return result;
    }
};
