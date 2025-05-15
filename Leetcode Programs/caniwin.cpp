#pragma clang attribute push ([[gnu::target("sse2,sse3,sse4.1,sse4.2,avx,avx2,popcnt,fma,bmi,bmi2,lzcnt")]], apply_to=function)
#include <ranges>
namespace {
    const char _ = []{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
    using u8  = uint8_t;
    using u16 = uint16_t;
    using u32 = uint32_t;
    using u64 = uint64_t;
    u32 sum[1 << 20];
    bool dp[1 << 20];
    bool table[21][301];
    char init = []{
        for (u32 s = 1; s < (1u << 20); ++s)
            sum[s] = sum[s - (s & -s)] + countr_zero(s & -s) + 1;
        auto solve = [](u32 n, u32 tot) -> bool {
            if (tot <= n) return true;
            if ((1 + n) * n / 2 < tot) return false;
            if ((1 + n) * n / 2 == tot) return n % 2;
            fill_n(dp, 1 << n, false);
            for (u32 s = 1u << n; s--; ) {
                if (sum[s] >= tot) continue;
                for (u32 t = (~s) & ((1 << n) - 1), i; (i = t & -t); t -= i) {
                    if (!dp[s | i]) {
                        dp[s] = true;
                        break;
                    }
                }
            }
            return dp[0];
        };
        for (u32 n = 1; n <= 20; ++n)
            for (u32 s = 0; s <= 300; ++s)
                table[n][s] = solve(n, s);
        return 0;
    }();
}

class Solution {
public:
    bool canIWin(u32 n, u32 tot) {
        return table[n][tot];
    }
};

#pragma clang attribute pop
