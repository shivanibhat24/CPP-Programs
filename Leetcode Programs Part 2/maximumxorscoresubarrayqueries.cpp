const int N = 2000;
int dp[N][N];
class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for(int i=0;i<n;i++)dp[0][i]=nums[i];
        for(int i=1;i<n;i++)
        for(int j=0;j<n-i;j++)dp[i][j]=dp[i-1][j]^dp[i-1][j+1];        
        for(int i=1;i<n;i++)
        for(int j=0;j<n-i;j++)
                dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i-1][j+1]));
        vector<int> ans;
        for(auto&q:queries){
            ans.push_back(dp[q[1]-q[0]][q[0]]);
        }
        return ans;
    }
};
