class Solution {
public:
    int findNthDigit(int n) {
        if(n <= 9) return n;
        if(n == 10) return 1;
        long long i = 1;
        long long m = 9;
        long long x = i * m * pow(10LL, i - 1); 
        long long digits = 0;
        while(n >= x) {
            n -= x;
            digits = digits * 10 + 9;
            i++;
            x = i * m * pow(10LL, i - 1);
        }
        long long div = n / i;
        long long rem = n % i;
        long long numbersize = i;
        long long ans;
        if(rem == 0) return (digits + div) % 10;
        long long temp = digits + div + 1;
        while(numbersize >= rem) {
            ans = temp % 10;
            temp /= 10;
            numbersize--;
        }
        return (int)ans;
    }
};
