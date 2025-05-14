class Solution {
public:
    int parents[50000];
    int lengths[50000];
    int parent(int node) {
        if(parents[parents[node]] != parents[node]) {
            parents[node] = parent(parents[node]);
        }
        return parents[node]; 
    }
    long long maxScore(int n, vector<vector<int>>& edges) {
        iota(parents, parents + n, 0);
        fill(lengths, lengths + n, 1);
        vector<int> cycles;
        vector<int> segments;
        for(const auto& edge: edges) {
            int p_a = parent(edge[0]);
            int p_b = parent(edge[1]);
            if(p_a == p_b) {
                cycles.push_back(lengths[p_a]);
                lengths[p_a] = 0;
            } else {
                parents[p_b] = p_a;
                lengths[p_a] += lengths[p_b];
                lengths[p_b] = 0;
            }
            if(lengths[p_a] < lengths[p_b]) {
                swap(p_a, p_b);
            }
        }
        for(int i = 0; i < n; i++) {
            if(lengths[i] > 0) {
                segments.push_back(lengths[i]); 
            }
        }
        sort(cycles.begin(), cycles.end());
        sort(segments.begin(), segments.end(), greater<int>());
        long total = 0;
        for(int cycle: cycles) {
            total += processCycle(cycle, n);
            n -= cycle;
        }
        for(int segment: segments) {
            total += processSegment(segment, n);
            n -= segment;
        }
        return total;
    }
    long processCycle(int length, long n) {
        long total = 0;
        long left = n;
        long right = n;
        n--;
        for(int i = 1; i < length; i++) {
            if(i % 2 == 1) {
                total += n * right;
                right = n--;
            } else {
                total += n * left;
                left = n--; 
            }
        }
        total += left * right; 
        return total;
    }
    long processSegment(int length, long n) {
        long total = 0;
        long left = n;
        long right = n;
        n--;
        for(int i = 1; i < length; i++) {
            if(i % 2 == 1) {
                total += n * right;
                right = n--;
            } else {
                total += n * left;
                left = n--; 
            }
        }
        return total;
    }
};
