#define ll long long
class Solution {
public:
    int MOD = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> nums(n);
        for(int i = 0; i < n; i++) {
            nums[i] = {efficiency[i], speed[i]};
        }
        sort(nums.begin(), nums.end(), [](pair<int, int>& p1, pair<int, int>& p2) {
            return p1.first > p2.first;
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        ll i = 0, sum = 0;
        ll ans = 0;
        while(i < n) {
            pq.push(nums[i].second);
            sum += nums[i].second;
            while(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sum*nums[i].first);
            i++;
        }
        return ans%MOD;
    }
};
