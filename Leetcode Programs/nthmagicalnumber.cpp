class Solution {
public:
    long long mod = 1000000007;
    int findLCM(int a, int b) { return abs(a * b) / std::gcd(a, b); }
    int nthMagicalNumber(int n, int a, int b) {
        long long ans;
        long long x = min(a, b), y = max(a, b);
        if (x == y) {
            ans = x * n;
            return ans % mod;
        }
        if (x * n <= y) {
            ans = x * n;
            return ans % mod;
        }
        long long gcd = findLCM(a, b);
        long long start = 1, end = x * n + 1;
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            int cnt = 0;
            cnt += (mid / x);
            cnt += (mid / y);
            cnt -= (mid / gcd);
            cout << cnt << endl;
            if (cnt == n) {
                if (mid % a == 0 || mid % b == 0) {

                    return mid%mod;
                }
                end=mid-1;
            } else if (cnt < n) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return findLCM(a, b);
    }
};
