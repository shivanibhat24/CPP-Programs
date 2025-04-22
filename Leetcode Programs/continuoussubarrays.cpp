auto init = []() -> bool {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return true;
}();

class Solution {
public:
    struct Map {
        unordered_map<int, int> mp;

        int size() {
            return mp.size();
        }

        int diff() {
            int mn = 1e9 + 5, mx = -1e9 - 5;
            for(auto& [k, v] : mp)
                mn = min(mn, k), mx = max(mx, k);
            return abs(mn - mx);
        }

        int sum() {
            int s = 0; 
            for(auto& [k, v] : mp) {
                s += v;
            }
            return s;
        }

        void add(int x) {
            mp[x]++;
        }

        void rm(int x) {
            mp[x]--;
            if (!mp[x])
                mp.erase(x);
        }
    };

    long long continuousSubarrays(vector<int>& nums) {
        const int n = nums.size();
        
        long long res = 0;
        Map mp;
        for(int l=0, r=0; r<n; r++) {
            mp.add(nums[r]);
            while (mp.size() > 3) {
                mp.rm(nums[l++]);
            }
            while (mp.diff() > 2) {
                mp.rm(nums[l++]);
            }
            res += mp.sum();
        }
        return res;
    }
};
