class Solution {
public:
    int maxFrequencyScore(vector<int>& A, long long k) {
        int i = 0, n = A.size();
        sort(A.begin(), A.end());
        for (int j = 0; j < n; ++j)
            if ((k -= A[j] - A[(i + j) / 2]) < 0)
                k += A[(i + j + 1) / 2] - A[i++];
        return n - i;
    }
};
