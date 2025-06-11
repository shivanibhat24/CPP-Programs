class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v2(n);
        int maxv2 = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i], c = 0;
            while ((x & 1) == 0) { c++; x >>= 1; }
            v2[i] = c;
            maxv2 = max(maxv2, c);
        }        
        vector<vector<int>> pre(maxv2+1, vector<int>(n+1,0));
        for (int e = 0; e <= maxv2; e++) {
            for (int i = 0; i < n; i++) {
                pre[e][i+1] = pre[e][i] + (v2[i]==e);
            }
        }        
        vector<pair<int,long long>> f_old, f_new;
        long long best1 = 0, best2 = 0;
        for (int i = 0; i < n; i++) {            
            f_new.clear();
            f_new.emplace_back(nums[i], 1);
            for (auto &p : f_old) {
                int g = std::gcd(p.first, nums[i]);
                if (f_new.back().first == g)
                    f_new.back().second += p.second;
                else
                    f_new.emplace_back(g, p.second);
            }           
            long long cum = 0;
            for (auto &p : f_new) {
                int g = p.first;
                long long cnt = p.second;
                long long up = cum + cnt;    
                best1 = max(best1, (long long)g * up);              
                int m = __builtin_ctz(g);
                auto need = [&](long long L){                  
                    return pre[m][i+1] - pre[m][i - L + 1];
                };
                long long lo = cum+1, hi = up;
                if (need(lo) <= k) {
                    long long ok = lo;
                    while (lo <= hi) {
                        long long mid = (lo+hi)/2;
                        if (need(mid) <= k) {
                            ok = mid;   lo = mid+1;
                        } else {
                            hi = mid-1;
                        }
                    }
                    best2 = max(best2, (long long)g * ok);
                }                
                cum = up;
            }
            swap(f_old, f_new);
        }       
        return max(best1, best2*2LL);
    }
};
