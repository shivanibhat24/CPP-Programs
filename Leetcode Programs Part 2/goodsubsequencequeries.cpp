class Solution {
public:
    int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {        
        int n = nums.size();
        vector<int> tree(2 * n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % p == 0) {
                tree[n + i] = nums[i];
                cnt++;
            }
        }
        for (int i = n - 1; i > 0; i--) {
            tree[i] = __gcd(tree[2 * i], tree[2 * i + 1]);
        }
        int ans = 0;
        for (auto &q : queries) {
            int idx = q[0];
            int val = q[1];
            if (nums[idx] % p == 0) cnt--;
            if (val % p == 0) cnt++;
            nums[idx] = val;
            int pos = n + idx;
            tree[pos] = (val % p == 0 ? val : 0);
            while (pos > 1) {
                pos /= 2;
                tree[pos] = __gcd(tree[2 * pos], tree[2 * pos + 1]);
            }
            int g = tree[1];
            if (g == p) {
                if (cnt < n) {
                    ans++; 
                } else if (n < 10) {
                    bool found = false;
                    for (int i = 0; i < n && !found; i++) {
                        int temp = 0;
                        for (int j = 0; j < n; j++) {
                            if (i != j) {
                                temp = __gcd(temp, nums[j]);
                            }
                        }
                        if (temp == p) found = true;
                    }
                    if (found) ans++;
                } else {
                    ans++;
                }
            }
        }
        return ans;
    }
};
