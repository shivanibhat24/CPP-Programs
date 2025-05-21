class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    vector<int> getAllMaskForCurrentRow(int row,int prevRowMask,vector<int> &seats){
        vector<int> ans;
        for(int mask=0;mask<(1<<n);mask++){
            if((mask & seats[row]) != mask) continue; 
            if(((prevRowMask>>1) & mask) != 0 ) continue;
            if(((prevRowMask<<1) & mask) !=0 ) continue;
            if((mask & (mask>>1)) != 0) continue;
            if((mask & (mask<<1)) != 0) continue;
            ans.push_back(mask);
        }
        return ans;
    }
    int solve(int row,int prevRowMask,vector<int>& seats){
        if(row==m) return 0;
        if(dp[row][prevRowMask]!=-1) return dp[row][prevRowMask];
        vector<int> newMasks = getAllMaskForCurrentRow(row,prevRowMask,seats);
        int ans = 0;
        for(int mask:newMasks){
            ans = max(ans, __builtin_popcount(mask) + solve(row+1,mask,seats));
        }
        return dp[row][prevRowMask] = ans;
    }
    int maxStudents(vector<vector<char>>& seats) {
        m = size(seats), n = size(seats[0]);
        dp.resize(m,vector<int> (1<<n,-1));
        vector<int> v;
        for(int i=0;i<m;i++){
            int curr = 0;
            for(int j=0;j<n;j++){
               curr = curr * 2 + (seats[i][j] == '.');
            }
            v.push_back(curr);
        }
        return solve(0,0,v);
    }
};
