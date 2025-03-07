class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        long long ans, mid, low = 0, high = k + n * 100000ll, start = 0;
        for(int i=0; i<r; i++) start += stations[i];
        vector<int> stat(n);
        while(low <= high) {
            mid = low + (high - low) / 2;
            copy(stations.begin(), stations.end(), stat.begin());
            long long sum = start, cnt = 0;
            for(int i=0; i<n; i++) {
                if(i+r < n) sum += stat[i+r];
                if(i-r > 0) sum -= stat[i-r-1];
                if(sum < mid) {
                    long long new_stat = mid - sum;
                    stat[min(i+r,n-1)] += new_stat;
                    cnt += new_stat;
                    if(cnt > k) break;
                    sum = mid;
                }
            }
            if(cnt > k) high = mid - 1;
            else {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
};
