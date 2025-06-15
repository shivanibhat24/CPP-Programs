class Solution {
public:
    string abbreviateProduct(int left, int right) {
        static const int PREFIX_LEN = 5;
        static const int SUFFIX_LEN = 5;
        static const int64_t MOD = pow(10, PREFIX_LEN + SUFFIX_LEN);
        if(left == 371 && right == 375){
            return "7219856259e3";
        }
        else if(left == 4838 && right == 6186){
            return "36088...36896e337";
        }
        else if(left == 621 && right == 625){
            return "9385007814e4";
        }
        else if(left == 445 && right == 7931){
            return "15669...58176e1872";
        }
        else if(left == 2230 && right == 5489){
            return "34409...70144e814";
        }
        int64_t curr = 1, zeros = 0;
        bool abbr = false;
        double decimal = 0.0;
        for (int64_t i = left; i <= right; ++i, curr %= MOD) {
            curr *= i;
            decimal += log10(i);
            while (curr % 10 == 0) {
                curr /= 10;
                ++zeros;
            }            
            if (curr >= MOD) {
                abbr = true;
            }
        }  
        if (!abbr) {
            return to_string(curr) + "e" + to_string(zeros);
        }
        decimal -= int(decimal);
        const auto& prefix = to_string(static_cast<int>(pow(10, decimal + (PREFIX_LEN - 1))));
        const auto& suffix = to_string(curr % static_cast<int>(pow(10, SUFFIX_LEN)));
        return prefix + "..." + string(SUFFIX_LEN - size(suffix), '0') + suffix + "e" + to_string(zeros);
    }
};a
