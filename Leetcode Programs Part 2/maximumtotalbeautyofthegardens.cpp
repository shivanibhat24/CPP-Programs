class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        int n = flowers.size();
        long long left_flowers = newFlowers - 1LL * target * n;
        for (int& flower : flowers) {
            flower = min(flower, target);
            left_flowers += flower;
        }
        long long a = 0;
        for (int& flower : flowers) {
            a += target - flower;
        }        
        long long b = newFlowers - a;
        if (b == newFlowers) {
            return 1LL * n * full;
        }
        if (b >= 0) {
            return max(1LL * (target - 1) * partial + 1LL * (n - 1) * full, 1LL * n * full);
        }
        ranges::sort(flowers); 
        long long ans = 0, pre_sum = 0;
        int j = 0;        
        for (int i = 1; i <= n; i++) {
            b += target - flowers[i - 1];
            if (b < 0) {
                continue;
            }
            while (j < i && 1LL * flowers[j] * j - pre_sum <= b) {
                pre_sum += flowers[j];
                j++;
            }            
            long long avg = (b + pre_sum) / j;
            long long total_beauty = avg * partial + 1LL * (n - i) * full;
            ans = max(ans, total_beauty);
        }
        return ans;
    }
};
