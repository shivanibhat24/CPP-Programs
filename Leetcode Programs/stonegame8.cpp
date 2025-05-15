class Solution {
public:
    int stoneGameVIII(const vector<int>& stones) const {
        const int N = stones.size();
        int sum = vector_sum(stones);
        int max_score = sum;
        sum -= stones[N - 1];
        for (int pos = N - 2; pos > 0; --pos) {
            max_score = max(max_score, sum - max_score);
            sum -= stones[pos];
        }
        return max_score;
    }
    static int vector_sum(const vector<int>& v) {
        int sum = 0;
        size_t i = 0;
        for (; i + 4 <= v.size(); i += 4) {
            sum += v[i] + v[i + 1] + v[i + 2] + v[i + 3];
        }
        for (; i < v.size(); ++i) {
            sum += v[i];
        }
        return sum;
    }
};
static const int __FAST__ = []{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
