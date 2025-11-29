class Solution {
private:
    int gcd(int a, int b) {
        while (b) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    }
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) return 0;
        struct SegmentInfo {
            int dx, dy;
            long long K;            
            bool operator<(const SegmentInfo& other) const {
                if (dy != other.dy) return dy < other.dy;
                if (dx != other.dx) return dx < other.dx;
                return K < other.K;
            }            
            bool sameSlope(const SegmentInfo& other) const {
                return dx == other.dx && dy == other.dy;
            }            
            bool sameLine(const SegmentInfo& other) const {
                return dx == other.dx && dy == other.dy && K == other.K;
            }
        };
        struct DiagonalInfo {
            int mx, my; 
            int dx, dy;
            bool operator<(const DiagonalInfo& other) const {
                if (mx != other.mx) return mx < other.mx;
                if (my != other.my) return my < other.my;
                if (dx != other.dx) return dx < other.dx;
                return dy < other.dy;
            }
        };
        int num_pairs = n * (n - 1) / 2;
        vector<SegmentInfo> segments;
        vector<DiagonalInfo> diagonals;
        segments.reserve(num_pairs);
        diagonals.reserve(num_pairs);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int raw_dx = points[j][0] - points[i][0];
                int raw_dy = points[j][1] - points[i][1];
                int mx = points[i][0] + points[j][0];
                int my = points[i][1] + points[j][1];
                int g = gcd(std::abs(raw_dx), std::abs(raw_dy));
                int dx = raw_dx / g;
                int dy = raw_dy / g;
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }
                long long K = (long long)dy * points[i][0] - (long long)dx * points[i][1];
                segments.push_back({dx, dy, K});
                diagonals.push_back({mx, my, dx, dy});
            }
        }
        sort(segments.begin(), segments.end());
        long long tpp = 0;
        int m = segments.size();
        int i = 0;
        while (i < m) {
            int j = i;
            while (j < m && segments[i].sameSlope(segments[j])) {
                j++;
            }
            long long totalSegmentsInSlope = 0;
            long long sumSqSegments = 0;
            int k = i;
            while (k < j) {
                int l = k;
                while (l < j && segments[k].sameLine(segments[l])) {
                    l++;
                }
                long long cnt = l - k;
                totalSegmentsInSlope += cnt;
                sumSqSegments += cnt * cnt;
                k = l;
            }
            tpp += (totalSegmentsInSlope * totalSegmentsInSlope - sumSqSegments) / 2;
            i = j;
        }
        sort(diagonals.begin(), diagonals.end());        
        long long parallelograms = 0;
        int p_idx = 0;
        int p_m = diagonals.size();        
        while (p_idx < p_m) {
            int next_p = p_idx;
            while (next_p < p_m && 
                   diagonals[p_idx].mx == diagonals[next_p].mx && 
                   diagonals[p_idx].my == diagonals[next_p].my) {
                next_p++;
            }
            long long total_in_group = next_p - p_idx;
            long long sum_sq_slope_counts = 0;            
            int s_idx = p_idx;
            while (s_idx < next_p) {
                int next_s = s_idx;
                while (next_s < next_p && 
                       diagonals[s_idx].dx == diagonals[next_s].dx && 
                       diagonals[s_idx].dy == diagonals[next_s].dy) {
                    next_s++;
                }                
                long long count_slope = next_s - s_idx;
                sum_sq_slope_counts += count_slope * count_slope;                
                s_idx = next_s;
            }
            parallelograms += (total_in_group * total_in_group - sum_sq_slope_counts) / 2;            
            p_idx = next_p;
        }
        return (int)(tpp - parallelograms);
    }
};
