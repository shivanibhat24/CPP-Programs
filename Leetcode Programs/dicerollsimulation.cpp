class Solution
{
    static array<long, 5001> sum;
    static array<array<long, 6>, 5001> dp;
    static const long p;
    static size_t last_n;
public:
    int dieSimulator(const int &n, const vector<int>& rollMax)
    {
        [[assume(1 <= last_n and last_n <= 5000)]];
        [[assume(1 <= n and n <= 5000)]];
        memset(sum.data() + 1, 0, sizeof(long) * last_n);
        memset(dp.data() + 1, 0, sizeof(long) * last_n * 6);
        last_n = n;
        for (int i = 1; i != n + 1; i++)
        {
            for (int j = 0; j != 6; j++)
            {
                const int &maxroll = rollMax[j];
                [[assume(1 <= maxroll and maxroll <= 15)]];
                for (int k = 1; k != 1 + maxroll and k != i + 1; k++)
                {
                    dp[i][j] = (dp[i][j] + sum[i - k] - dp[i - k][j] + p) % p;
                }
                sum[i] = (sum[i] + dp[i][j]) % p;
            }                
        }
        return sum[n];
    }
};
size_t Solution::last_n = 1;
array<long, 5001> Solution::sum{1};
array<array<long, 6>, 5001> Solution::dp{};
constexpr long Solution::p = 1e9 + 7;
