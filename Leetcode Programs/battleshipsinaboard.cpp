class Solution {
private:
    void dfs(vector<vector<char>>& board,vector<vector<int>>&vis,int n,int m,int r,int c){
        vis[r][c] = 1;
        if(c-1>=0 && board[r][c-1]=='X'&& vis[r][c-1]==0) dfs(board,vis,n,m,r,c-1);
        if(c+1<m && board[r][c+1]=='X'&& vis[r][c+1]==0) dfs(board,vis,n,m,r,c+1);
        if(r-1>=0 && board[r-1][c]=='X'&& vis[r-1][c]==0) dfs(board,vis,n,m,r-1,c);
        if(r+1<n && board[r+1][c]=='X'&& vis[r+1][c]==0) dfs(board,vis,n,m,r+1,c);
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int battleships = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X' && vis[i][j]==0){
                    battleships++;
                    dfs(board,vis,n,m,i,j);
                }
            }
        } 
        return battleships;
    }
};
