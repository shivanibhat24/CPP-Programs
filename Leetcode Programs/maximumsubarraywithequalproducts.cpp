class Solution {
public:
    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }
    int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
    int maxLength(vector<int>& nums) {
        int n = nums.size(), maxi = 0;
        for (int i = 0; i < n; ++i) {
            int prod = nums[i], G = nums[i], L = nums[i];
            if (prod == G * L) maxi = max(maxi, 1);
            for (int j = i + 1; j < n; ++j) {
                if ((long long)prod * nums[j] > INT_MAX) break;
                prod *= nums[j];
                G = gcd(G, nums[j]);
                L = lcm(L, nums[j]);
                if (prod == G * L) maxi = max(maxi, j - i + 1);
                else break;
            }
        }
        return maxi;
    }
};
