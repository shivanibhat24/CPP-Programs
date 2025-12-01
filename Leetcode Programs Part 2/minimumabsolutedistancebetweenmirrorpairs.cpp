class Solution {
public:
        int reverse(int a) {
        int b = 0;
        while (a > 0) {
            b = b * 10 + a % 10;
            a /= 10;
        }
        return b;
    }

    int minMirrorPairDistance(const std::vector<int>& A) {
        unordered_map<int, int> pre;
        int n = A.size(), res = n;
        for (int i = 0; i < n; ++i) {
            if (pre.count(A[i])) {
                res = min(res, i - pre[A[i]]);
            }
            pre[reverse(A[i])] = i;
        }

        return (res < n) ? res : -1;
    }
};
