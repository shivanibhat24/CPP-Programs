class Solution {
public:
    int kthGrammar(int n, int k) {
        bool areValuesSame = true; 
        n = pow(2, n - 1);
        while (n != 1) {
            n /= 2;
            if (k > n) {
                k -= n;
                areValuesSame = !areValuesSame;
            }
        }
        return ((areValuesSame) ? 0 : 1) ;
    }
};
