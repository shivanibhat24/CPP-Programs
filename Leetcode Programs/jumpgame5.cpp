class Solution {
public:
    vector<int> dp, arr;
    int n, d;
    int rec (int i) {
        if(dp[i] != INT_MIN) {
            return dp[i];
        }
        int ans = 0;
        for(int j = i+1; j <= i+d && j < n; j++) {
            if(arr[i] > arr[j])
                ans = max(ans, rec(j));
            else
                break;
        }
        for(int j = i-1; j >= i-d && j >= 0; j--) {
            if(arr[i] > arr[j])
                ans = max(ans, rec(j));
            else
                break;
        }
        dp[i] = ans+1;
        return ans+1;
    }
    int maxJumps(vector<int>& arr, int d) {
        this->d = d;
        this->n = arr.size();
        this->arr = arr;
        this->dp = vector<int> (n, INT_MIN);
        int ans = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(dp[i] == INT_MIN)
                ans = max(ans, rec(i));
        }
        return ans;
    }
};
