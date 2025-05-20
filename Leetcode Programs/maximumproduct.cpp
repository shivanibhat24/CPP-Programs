class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        for (int i = n-1; i >= 0; i--) {
            bool aset = (a &(1ull<<i));
            bool bset = (b & (1ull << i));
            if (aset && bset) continue;
            if (!aset && !bset) {
                a ^= (1ull << i);
                b ^= (1ull << i);
            } 
            if (aset) {
                if (a > b) {
                    a ^= (1ull << i);
                    b ^= (1ull << i);
                }
            }
            if (bset) {
                if (b > a) {
                    a ^= (1ull << i);
                    b ^= (1ull << i);
                }
            }
        }   
        a %= 1000000007;
        b %= 1000000007;
        return (a*b) % 1000000007;
    }
};
