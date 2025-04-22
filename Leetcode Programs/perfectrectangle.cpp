#define MOD 113
#define P 31

class Solution {
    int corners[MOD];
    int sum = 0;
    inline long long area(const vector<int> &r) {
        return (long long)(r[2] - r[0]) * (r[3] - r[1]);
    }
    inline void add(const pair<int, int> &p) {
        int& v = corners[((p.first * P + p.second) % MOD + MOD) % MOD];
        v ^= 1;
        sum += (v == 1 ? 1 : -1);
    }
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
    long long sum_area = 0;
        int x0 = 1e5, y0 = 1e5, x1 = -1e5, y1 = -1e5;

        for (const auto &r : rectangles) {
            sum_area += area(r);
            x0 = (x0 < r[0] ? x0 : r[0]);
            y0 = (y0 < r[1] ? y0 : r[1]);
            x1 = (x1 > r[2] ? x1 : r[2]);
            y1 = (y1 > r[3] ? y1 : r[3]);
            add({r[0], r[1]});
            add({r[2], r[3]});
            add({r[0], r[3]});
            add({r[2], r[1]});
        }
        add({x0, y0});
        add({x1, y0});
        add({x0, y1});
        add({x1, y1});
        // cout << x0 << " " << y0 << " " << x1 << " " << y1 << "\n";
        return area({x0, y0, x1, y1}) == sum_area && sum == 0;   
    }
};
