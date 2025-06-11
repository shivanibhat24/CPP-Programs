class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1'000'000'007;
        int n = nums.size();
        deque<int> min_q, max_q;
        vector<int> f(n + 1);
        f[0] = 1;
        long long sum_f = 0;
        int left = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            sum_f += f[i];
            while (!min_q.empty() && x <= nums[min_q.back()]) {
                min_q.pop_back();
            }
            min_q.push_back(i);
            while (!max_q.empty() && x >= nums[max_q.back()]) {
                max_q.pop_back();
            }
            max_q.push_back(i);
            while (nums[max_q.front()] - nums[min_q.front()] > k) {
                sum_f -= f[left];
                left++;
                if (min_q.front() < left) {
                    min_q.pop_front();
                }
                if (max_q.front() < left) {
                    max_q.pop_front();
                }
            }
            f[i + 1] = sum_f % MOD;
        }
        return f[n];
    }
};
