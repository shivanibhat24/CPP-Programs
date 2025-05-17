constexpr long mod = 1e9 + 7;
constexpr long inv[101] = {0, 1, 500000004, 333333336, 250000002, 400000003, 166666668, 142857144, 125000001, 111111112, 700000005, 818181824, 83333334, 153846155, 71428572, 466666670, 562500004, 352941179, 55555556, 157894738, 850000006, 47619048, 409090912, 739130440, 41666667, 280000002, 576923081, 370370373, 35714286, 758620695, 233333335, 129032259, 281250002, 939393946, 676470593, 628571433, 27777778, 621621626, 78947369, 717948723, 425000003, 658536590, 23809524, 395348840, 204545456, 822222228, 369565220, 404255322, 520833337, 448979595, 140000001, 784313731, 788461544, 56603774, 685185190, 763636369, 17857143, 385964915, 879310351, 50847458, 616666671, 688524595, 564516133, 15873016, 140625001, 30769231, 469696973, 686567169, 838235300, 579710149, 814285720, 98591550, 13888889, 410958907, 310810813, 93333334, 539473688, 831168837, 858974365, 202531647, 712500005, 123456791, 329268295, 84337350, 11904762, 670588240, 197674420, 252873565, 102272728, 415730340, 411111114, 164835166, 184782610, 43010753, 202127661, 231578949, 760416672, 268041239, 724489801, 646464651, 570000004};
class Fancy {
public:
    Fancy() {
    }
    
    void append(int val) {
        sequence.push_back((mult_inv * val + add_inv) % mod);
    }
    
    void addAll(int inc) {
        addition = (addition + inc) % mod;
        add_inv = ((add_inv - mult_inv * inc) % mod + mod) % mod;
    }
    
    void multAll(int mult) {
        multiplication = multiplication * mult % mod;
        addition = addition * mult % mod;
        long inverse = inv[mult];
        mult_inv = mult_inv * inverse % mod;
    }
    long powMod(long base, long exp, long mod) {
        long output = 1;
        while(exp > 0) {
            if(exp & 1) {
                output = output * base % mod;
            }
            base = base * base % mod;
            exp >>= 1;
        }
        return output;
    }
    long modInverse(long x, long mod) {
        return powMod(x, mod - 2, mod); 
    }
    
    int getIndex(int idx) {
        if(idx >= sequence.size()) {
            return -1;
        }
        long value = sequence[idx]; 
        value = (multiplication * value + addition) % mod;
        return value;
    }
private:
    vector<long> sequence;
    long addition = 0;
    long multiplication = 1; 
    long mult_inv = 1;
    long add_inv = 0;
};
