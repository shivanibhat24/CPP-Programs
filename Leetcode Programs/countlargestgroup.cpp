class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> frq;
        for (int i = 1; i <= n; i++) {
            int num = i, sum = 0;
            while(num) {
                sum += num % 10;       
                num /= 10;
            }
            frq[sum]++;
        }
        int  mxLen = -1, res = 0;
        for (auto &f:frq)
            mxLen = max(mxLen, f.second);
        for (auto &f:frq)
            if (f.second == mxLen) res++;
        return res;
    }
};
