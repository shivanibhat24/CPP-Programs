class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // number: frequency, first appearance, last appearance
        unordered_map<int, array<int, 3>> m;
        int targetfreq = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            if (m.find(n) == m.end()) {
                m[n] = {1, i, i};
            } else {
                ++m[n][0];
                m[n][2]=i;
            }

            targetfreq = max(targetfreq, m[n][0]);
        }

        int res = 1e9;
        for (auto& p : m) {
            int f = p.second[0];
            int fa = p.second[1];
            int la = p.second[2];
            if (f != targetfreq) continue;
            res=min(res, (la-fa+1));
        }
        return res;
    }
};
