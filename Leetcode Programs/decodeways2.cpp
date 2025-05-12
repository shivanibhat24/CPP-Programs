class Solution {
public:
    int numDecodings(string s) {
        long two_back = 1;
        long one_back = s[0] == '*' ? 9 : s[0] != '0';
        int mod = 1e9+7;
        for(int i = 1; i < s.length(); i++){
            long long one_digit = 0, two_digit = 0;
            switch(s[i]){
                case '*':
                    one_digit = (one_back * 9) % mod;
                    two_digit = TwoDigitWays(s[i], s[i-1], two_back);
                    break;
                case '0':
                    two_digit = TwoDigitWays(s[i], s[i-1], two_back);
                    if(two_digit == 0) return 0;
                    break;
                default:
                    one_digit = one_back;
                    two_digit = TwoDigitWays(s[i], s[i-1], two_back);
                    break;
            }
            int temp = one_back;
            one_back =  (one_digit + two_digit) % mod;
            two_back = temp;
            if(one_back == 0) return 0;
        }
        return one_back;
    }
    long TwoDigitWays(char ones_digit, char twos_digit, int two_back_ways){
        if(twos_digit == '0') return 0;
        long variation = 0;
        switch(twos_digit){
            case '*':
                switch(ones_digit){
                    case '*':
                        variation = 15;
                        break;
                    default:
                        if(ones_digit > '6') variation = 1;
                        else variation = 2;
                        break;
                }
                break;
            case '1':
                switch(ones_digit){
                    case '*':
                        variation = 9;
                        break;
                    default:
                        variation = 1;
                        break;
                }
                break;
            case '2':
                switch(ones_digit){
                    case '*':
                        variation = 6;
                        break;
                    default:
                        if(ones_digit <= '6') variation = 1;
                        break;
                }
                break;
        }
        return (variation * two_back_ways ) % 1000000007;
    }
};
