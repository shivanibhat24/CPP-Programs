using ll = long long;
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        ll sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) nums[i] = -nums[i];
            else sum += nums[i];
        }
        sort(nums.begin(), nums.end());
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
        pq.push({nums[0], 0});
        ll rem = 0;
        while (--k) {
            auto [v, i] = pq.top();
            pq.pop();
            rem = v;
            if (i + 1 < n) {
                pq.push({v + nums[i + 1], i + 1});
                pq.push({v + nums[i + 1] - nums[i], i + 1});
            }
        }
        return sum - rem;
    }
};
