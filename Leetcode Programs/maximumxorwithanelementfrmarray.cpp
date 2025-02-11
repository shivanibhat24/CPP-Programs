class Solution {
public:
    bool isOn(int val, int pos) {
        int mask = 1 << pos; 
        return (val & mask) != 0;
    }
    int solve(vector<int>& nums, int n, int x, int m) {
        if (nums[0] > m) {return -1;}
        int p1 = 0; int p2 = 0;
        int L = 0; int R = n-1;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (nums[mid] <= m) {
                L = mid+1;
                p2 = max(p2, mid);
            }
            else {
                R = mid-1;
            }
        }
        for (int i=31; i>=0; i--) {
            if (isOn(x, i)) {
                if (isOn(nums[p1], i)) {continue;}
                L = p1; R = p2;
                int nx = p1;
                while (L <= R) {
                    int mid = (L + R) / 2;
                    if (!isOn(nums[mid], i)) {
                        nx = max(nx, mid);
                        L = mid+1;
                    }
                    else {
                        R = mid-1;
                    }
                }
                p2 = nx;
            }
            else {
                if (!isOn(nums[p2], i)) {continue;}
                L = p1; R = p2;
                int nx = p2;
                while (L <= R) {
                    int mid = (L + R) / 2;
                    if (isOn(nums[mid], i)) {
                        nx = min(nx, mid);
                        R = mid-1;
                    }
                    else {
                        L = mid+1;
                    }
                }
                p1 = nx;
            }
        }
        return nums[p2] ^ x;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i=0; i<queries.size(); i++) {
            int a_i = solve(nums, n, queries[i][0], queries[i][1]);
            ans.push_back(a_i);
        }
        return ans;
    }
};
