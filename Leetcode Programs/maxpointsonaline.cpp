class Solution {  // Solution1: TC: O(n^2), SC: O(n). Hash Map of slope.
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0, n = points.size(), MOD = 33391;  // 33391
        if (n <= 1) return n;
        auto gcd = [](int a, int b, auto& gcd) -> int {
            return b == 0 ? a : gcd(b, a % b, gcd);
        };
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) -> bool {
            return a[0] < b[0] || a[0] == b[0] && a[1] < b[1];
        });
        vector<int> v(MOD, 0);  // v[i] is the number of unordered point pairs in the line with hash value i
        for (int i = 0, b = 0; i < n; i++) {
            while (b < n && points[b][0] == points[i][0]) b++;
            ans = max(ans, (b - i) * (b - i - 1) / 2);  // slope = +oo
            for (int j = b; j < n; j++) {  // starts with `b` to skip points with equal x values
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int g = gcd(dx, dy, gcd);
                dx /= g, dy /= g;  // dx/dy = m/n where gcd(m,n)=1, i.e., dx=g*m and dy=g*n, NOTE: dy may be 0 but it doesn't matter
                if (dx < 0) dx *= -1, dy *= -1;
                int px = points[i][0] - dx * (points[i][0] / dx);
                int py = points[i][1] - dy * (points[i][0] / dx);
                unsigned long long int h = ((((((px * 1ULL << 4) ^ py) << 4) ^ dx) << 4) ^ dy) % MOD;  // px, py, dx, dy >= 0
                ans = max(ans, ++v[h]);
            }
        }
        // cout << ans << endl;
        return round((1 + sqrt(1 + 8 * ans)) / 2);  // ans = (k * (k-1)) / 2 and k > 0  =>  k = (1 + sqrt(1 + 8 * ans)) / 2
    }
};

class Solution2 {  // Solution2: TC: O(n^2), SC: O(n). Hash Map of slope.
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        auto slope = [&points](int i, int j) -> double {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];
            return dx == 0 ? numeric_limits<float>::max() : dy * 1.0 / dx;
        };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> slopeMap;
            for (int j = i + 1; j < n; j++)  // NOTE: i+1..n-1 will cover all points in the line when i is the smallest index of the points in that line
                ans = max(ans, ++slopeMap[slope(i, j)]);
        }
        return ans + 1;
    }
};

class Solution3 {  // Solution3
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int max_num = 0;
        if (n == 1) {
            return 1;
        }
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> theta_map;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                double theta = atan2(dy, dx);
                theta_map[theta] ++;
            }
            for (auto& it : theta_map) {
                max_num = max(max_num, it.second + 1);
            }
        }
        return max_num;
    }
};
