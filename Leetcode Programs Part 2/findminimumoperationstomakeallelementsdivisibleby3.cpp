class Solution {
    public:
        static int minimumOperations(const vector<int>& a) {
                return accumulate(a.cbegin(), a.cend(), 0, [](int c, int x) { return c + (x % 3 > 0); });
                    }
                    };
