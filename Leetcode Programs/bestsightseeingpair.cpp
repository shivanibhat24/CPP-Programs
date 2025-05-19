class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxi = values[0];
        int ans = INT_MIN;
        for(int i = 1; i < n; i++) {
            maxi = max(maxi - 1, values[i - 1] - 1);
            ans = max(ans, maxi + values[i]);
        }
        return ans;
    }
};
