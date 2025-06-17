class Solution {
public:
    const int MOD = 1337;
    const int PHI_MOD = 1140;
    int power(int base, int exp, int modulus) {
        long long res = 1;
        base %= modulus;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % modulus;
            }
            base = (base * base) % modulus;
            exp /= 2;
        }
        return (int)res;
    }
    int superPow(int a, std::vector<int>& b) {
        if (b.empty()) {
            return 1;
        }
        int b_mod_phi = 0;
        for (int digit : b) {
            b_mod_phi = (b_mod_phi * 10 + digit) % PHI_MOD;
        }        
        int final_exponent;
        if (b_mod_phi == 0 && b.size() > 0) {
            final_exponent = PHI_MOD;
        } else if (b.size() == 1 && b[0] == 0) {
            final_exponent = 0;
        } else {
            final_exponent = b_mod_phi;
        }        
        return power(a, final_exponent, MOD);
    }
};
