long long items[100000];
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int N = size(nums);
        for (int i = 0; i < N; ++i) {
            int v = nums[i], s = 0;
            while (v) s += v % 10, v /= 10;
            items[i] = ((((long long)s << 32) | nums[i]) << 17) | i;
        }
        sort(items, items+N);
        int res = 0;
        for (int i = 0; i < N; ++i) {
            int u = items[i] & 0x1FFFF;
            while (u != i) {
                int v = u;
                u = items[u] & 0x1FFFF;
                items[v] &= ~0x1FFFF;
                items[v] |= v;
                ++res;
            }
        }
        return res;
    }
};
