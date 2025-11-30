namespace {
static constexpr unsigned modulo = 1000000007;

static constexpr unsigned max_n = 1000;
constexpr auto memo = []{
    std::array<unsigned[max_n], max_n> result{};
    auto* result_p = result.data();
    result_p[0][0] = 1;
    for (unsigned i = 1; i < max_n; ++i) {
        for (unsigned j = 0; j <= i && j < max_n; ++j) {
            result_p[i][j] = ((static_cast<unsigned long long>(i) * result_p[i-1u][j]) + (j == 0u ? 0u : result_p[i-1u][j-1u])) % modulo;
        }
    }

    return result;
}();

struct Solution {
    static constexpr int rearrangeSticks(int n, int k) noexcept {
        return memo[n-1][k-1];
    }
};
}
