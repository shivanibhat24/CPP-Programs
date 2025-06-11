class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long cost = 0;
        if(n > k){
            if(n % k == 0){
                cost += (long long)(pow(k, (n / k)));
            } else {
                cost += (long long)((long long)(n % k) * (long long)(n - (n % k)));
            }
        }
        if(m > k){
            if(m % k == 0){
                cost += (long long)(pow(k, (m / k)));
            } else {
                cost += (long long)((long long)(m % k) * (long long)(m - (m % k)));
            }
        }
        return cost;
    }
};
