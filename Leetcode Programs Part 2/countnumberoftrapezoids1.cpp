class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int size_p = points.size();
        pair<int, int> points_sorted[size_p];
        for (int index = 0; index < size_p; ++index) {
            points_sorted[index].first = points[index][0], points_sorted[index].second = points[index][1];
        }
        sort(&points_sorted[0], &points_sorted[0] + size_p, [&](pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second < p2.second;
        });
        long long result = 0ll, total_pairs = 0ll, count_current = 1ll;
        for (int index = 1; index < size_p; ++index) {
            if (points_sorted[index - 1].second == points_sorted[index].second) {
                ++count_current;
            } else {
                count_current = (count_current * (count_current - 1ll)) >> 1, result = (result + total_pairs * count_current) % 1000000007ll, total_pairs += count_current, count_current = 1ll;
            }
        }
        count_current = (count_current * (count_current - 1ll)) >> 1, result = (result + total_pairs * count_current) % 1000000007ll;
        return result;
    }
};
