class Solution {
public:
    void solve(int n,int col,vector<string> &cur,vector<int> &row,vector<int>&diagonal1,vector<int> & diagonal2,vector<vector<string>> &ans)
    {
        if(col==n){
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<n;i++){
            if(row[i]==0 && diagonal1[i+col]==0 && diagonal2[n-1+col-i]==0){
                row[i]=1;
                diagonal1[i+col]=1;
                diagonal2[n-1+col-i]=1;
                cur[i][col]='Q';
                solve(n,col+1,cur,row,diagonal1,diagonal2,ans);
                row[i]=0;
                diagonal1[i+col]=0;
                diagonal2[n-1+col-i]=0;
                cur[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> cur(n,s);
        vector<int> row(n,0),diagonal1(2*n,0),diagonal2(2*n,0);
        solve(n,0,cur,row,diagonal1,diagonal2,ans);
        return ans;
    }
};
