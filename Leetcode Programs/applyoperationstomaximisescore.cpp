#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 100000;
int spf[MAXN + 1];

auto init = []() {
    memset(spf, -1, sizeof(spf));
    spf[0] = spf[1] = 0;
    for(int i = 2; i <= MAXN; i++) {
        if(spf[i] == -1) {
            spf[i] = i;
            if(i > 317) continue;
            for(int j = i * i; j <= MAXN; j += i) {
                if(spf[j] == -1) spf[j] = i;
            }
        }
    }
    return 0;
}();
void compute(auto& nums, auto& res, const auto& cmp, bool reverse) {
    int n = nums.size();
    vector<int> stk;
    for(int i = reverse ? n-1 : 0, delta = reverse ? -1 : +1; 0 <= i && i < n; i += delta) {
        while(!stk.empty() && cmp(nums[i], nums[stk.back()])) {
            res[stk.back()] = i;
            stk.pop_back();
        }
        stk.push_back(i);
    }
}

int distinct(int n) {
    if(n <= 1) return 0;
    int cnt = 0, last = 0;
    while(n > 1) {
        if(spf[n] > last) {
            cnt++, last = spf[n];
        }
        n /= spf[n];
    }
    return cnt;
}

long long mod_exp(long long base, int exp, long long mod) {
    long long ans = 1;
    base %= mod;
    while(exp > 0) {
        if(exp & 1) ans = (ans * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return ans;
}

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> factors(n), nextGreater(n, n), prevGreater(n, -1);

        for(int i = 0; i < n; i++) {
            factors[i] = distinct(nums[i]);            
        }
        compute(factors, nextGreater, [](int a, int b) { return a > b; }, false);
        compute(factors, prevGreater, [](int a, int b) { return a >= b; }, true);

        priority_queue<array<int, 2>> pq;
        for(int i = 0; i < n; i++) {
            int left = prevGreater[i] + 1, right = nextGreater[i] - 1;

            // sum from x = (left) -> (i) : right - x + 1
            // sum from x = (left) -> (i) : (right + 1) - x
            // (i - left + 1) * (right + 1) - sum from x = (left) -> (i) : x
            // (i - left + 1) * (right + 1) - sum from x = (left) -> (i) : x
            // (i - left + 1) * (right + 1) - (left + (left + 1) + ... + i)
            // (i - left + 1) * (right + 1) - (i - left + 1) * (left + i) / 2
            // (i - left + 1) * (right + 1 - (left + i) / 2)
            // (i - left + 1) * ([2right + 2 - (left + i)] / 2)
            // (i - left + 1) * ([2right + 2 - left - i] / 2)
            // (i - left + 1) * (2right - left - i + 2) / 2
            int ch_left = i - left + 1;
            int ch_right = right - i + 1;
            long long cnt = 1LL * ch_right * ch_left;
            // cout << "i = " << i << ", nums[i] = " << nums[i] << ", factors[i] = " << factors[i] << ", cnt = " << cnt << '\n';
            // cout << "Range [" << left << ", " << right << "]\n";
            pq.push({nums[i], (int) min(cnt, (long long) 1e9)});
        }
        long long ans = 1;
        while(!pq.empty() && k > 0) {
            auto [mult, cnt] = pq.top();
            pq.pop();
            int take = min(k, cnt);
            // cout << "Take " << take << "x of score = " << mult << '\n';
            // cout << "MEXP: " << mod_exp(mult, take, MOD) << '\n';
            ans = (ans * mod_exp(mult, take, MOD)) % MOD;
            k -= take;
        }
        return ans;
    }
};
