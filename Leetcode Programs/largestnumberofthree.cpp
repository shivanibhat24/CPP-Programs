class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> count(10, 0);
        int sum = 0;
        for (int d : digits) {
            count[d]++;
            sum += d;
        }        
        auto removeDigits = [&](int mod) {
            for (int i = mod; i < 10; i += 3) {
                if (count[i] > 0) {
                    count[i]--;
                    sum -= i;
                    return true;
                }
            }
            return false;
        };        
        if (sum % 3 == 1) {
            if (!removeDigits(1)) {
                removeDigits(2);
                removeDigits(2);
            }
        } else if (sum % 3 == 2) {
            if (!removeDigits(2)) {
                removeDigits(1);
                removeDigits(1);
            }
        }        
        string res;
        for (int i = 9; i >= 0; --i) {
            res += string(count[i], '0' + i);
        }
        
        if (!res.empty() && res[0] == '0') {
            return "0";
        }
        return res;
    }
};
