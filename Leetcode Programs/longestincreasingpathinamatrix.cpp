class Solution {
public:    
    int dp[201][201];
    bool isSafe(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }    
    int helper(vector<vector<int>>& matrix, int last, int i,int j) {
        if(!isSafe(i, j, matrix.size(), matrix[0].size()) or last >= matrix[i][j])      
            return 0;        
        if(dp[i][j] != -1) return dp[i][j];        
        int backward = max(helper(matrix,matrix[i][j],i-1,j), helper(matrix,matrix[i][j],i,j-1));
        int forward = max(helper(matrix,matrix[i][j],i+1,j), helper(matrix,matrix[i][j],i,j+1));     
        return dp[i][j] = 1 + max(backward, forward); 
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        memset(dp, -1, sizeof(dp));
        int res = INT_MIN;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                res = max(res, helper(matrix, INT_MIN, i, j));
            }
        }
        return res;
    }
};
