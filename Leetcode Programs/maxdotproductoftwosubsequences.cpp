class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dp[i][j]=max(dp[i-1][j-1]+nums1[i-1]*nums2[j-1], max(dp[i-1][j], dp[i][j-1]));
            }
        }
        if(dp[n][m]==0){
            int a[2]={nums1[0], nums1[0]}, b[2]={nums2[0], nums2[0]};
            for(int i=0; i<n; i++){
                a[0]=max(a[0], nums1[i]);
                a[1]=min(a[1], nums1[i]);
            }
            for(int i=0; i<m; i++){
                b[0]=max(b[0], nums2[i]);
                b[1]=min(b[1], nums2[i]);
            }
            int ans=INT32_MIN;
            for(int i=0; i<2; i++)for(int j=0; j<2; j++)ans=max(ans, a[i]*b[j]);
            return ans;
        }
        return dp[n][m];
    }
};
