class Solution {
public:
    int tribonacci(int n) {
        if (n < 2) return n;
        for (int i = 0, j = 1, k = 1; ; k += j + i, j = k - j - i, i = k - j - i)
            if (--n == 1) return k;
    }
};
