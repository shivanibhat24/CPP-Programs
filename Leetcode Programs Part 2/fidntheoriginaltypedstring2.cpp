
using ll = long long;
using ull = unsigned long long;


auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {

    struct mint{
        static constexpr int MOD = 1e9+7;
        int value;

        static mint create(auto newValue) { return {static_cast<int>(newValue % MOD)}; }
        static mint createAdd(auto newValue) { return {static_cast<int>(newValue >= MOD ? newValue - MOD : newValue)}; }
        auto operator+(mint rhs) { return createAdd(value + rhs.value); }
        auto operator-(mint rhs) { return createAdd(MOD + value - rhs.value); }

        auto& update0(auto newValue) { value = static_cast<int>(newValue); return *this; }
        auto& update(auto newValue) { return update0(newValue % MOD); }
        auto& updateAdd(auto newValue) { return update0(newValue >= MOD ? newValue - MOD : newValue); }
        // auto& operator+=(auto&& rhs) {return updateAdd(value + rhs.value); }
        auto& operator+=(auto&& rhs) {
            value += rhs.value;
            if (value >= MOD) value -= MOD;
            return *this;
        }
        auto& operator-=(auto&& rhs) {
            value -= rhs.value;
            if (value < 0) value += MOD;
            return *this;
        }
        auto& operator*=(ll rhs) { return update(value * rhs); }
    };

public:
    int possibleStringCount(string& word, int k) {
        int n = word.length();
        auto getCount = [&] (auto i) {
            auto j = word.find_first_not_of(word[i], i+1);
            if (j == std::string::npos) j = n;
            return j - i;
        };

        mint totalCount = {1};
        for (int idx = 0; idx < n;) {
            --k;
            auto count = getCount(idx);
            totalCount *= count;
            idx += count;
        }
        if (k <= 0) return totalCount.value;

        // vector<mint> curr(k, mint{1});
        auto pCurr = std::make_unique_for_overwrite<mint[]>(k);
        auto curr = pCurr.get();
        std::fill_n(curr, k, mint{1});
        for (int idx = 0; idx < n;) {
            auto count = getCount(idx);
            if (count > 1) {
                for (int i = k-1; i >= count; --i) {
                    curr[i] -= curr[i-count];
                }
                std::partial_sum(curr, curr+k, curr);
            }
            idx += count;
        }
        return (totalCount - curr[k-1]).value;
    }
};
