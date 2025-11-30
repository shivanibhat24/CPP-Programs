class Solution {
public:
    bool Self_dividing(int n) {
        int m = n;
        while (m) {
            int d = m % 10;
            m /= 10;
            if (d == 0)
                return false;
            if (n % d == 0)
                continue;
            else
                return false;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            bool x = Self_dividing(i);
            if (x)
                ans.push_back(i);
        }
        return ans;
    }
};
