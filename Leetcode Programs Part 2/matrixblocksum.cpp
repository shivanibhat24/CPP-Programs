class Solution {
public:
    vector<vector<int>> pre;
    int query(int r1, int c1, int r2, int c2){
        return (pre[r2+1][c2+1] -pre[r1][c2+1] -pre[r2+1][c1] +pre[r1][c1]);
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        pre = vector<vector<int>> (mat.size()+1, vector<int>(mat[0].size()+1, 0));
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
        for(int i=1; i<=mat.size(); i++){
            for(int j=1; j<=mat[0].size(); j++){
                pre[i][j] =mat[i-1][j-1] + pre[i][j-1]+pre[i-1][j] - pre[i-1][j-1];
            }
        }
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                int r1= i-k >=0?i-k:0;
                int r2= i+k <mat.size()?i+k:mat.size()-1;
                int c1= j-k >=0?j-k:0;
                int c2= j+k <mat[0].size()?j+k:mat[0].size()-1;
                ans[i][j] = query(r1,c1,r2,c2);
            }
        }
        return ans;
    }
};
