class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        const int N = nums.size();
        long long ret = N;
        long long rotations = 0;
        long long pops = 0;
        vector<pair<int, int>> positions(N);
        for (int i = 0; i < N; ++i) {
            positions[i] = {nums[i], i};
        }
        sort(positions.begin(), positions.end());
        for (int i = 1; i < N; ++i) {
            ret += positions[i - 1].second > positions[i].second ? N - i : 0;
        }
        return ret;
    }
};
