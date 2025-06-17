class Solution {
public:
vector <int> dir ={-1, -1, 0, -1, 1, -1, -1, 1, 0, 1, 1, 1, -1, 0, 1, 0};
bool isvalid(vector<vector<char>> & board ,int i,int j){
    return (i>=0 && j>=0 && i<board.size() && j<board[0].size());
}
int adjca(vector<vector<char>>& board,int i,int j){
    int c=0;
    for (int k=0;k<8;k++){
        int nx= i + dir[2*k];
        int ny= j + dir[2*k+1];
        if (isvalid(board,nx,ny) && board[nx][ny]=='M'){
            c++ ;
        }
        
    }
    return c;
}
    void dfs(vector<vector<char>> & board,vector<vector<bool>> & vis,int i,int j){
        if (i<0||j<0||i>=board.size()||j>=board[0].size() || vis [i][j]) return ;
        vis[i][j]=true;
        if (board[i][j]=='M'){
            board[i][j]='X';
            return;
        }
        if (board[i][j]=='E'){
            int c= adjca(board,i,j);
            if (c==0){
                board[i][j]='B';
                for (int k=0;k<8;k++){
                    int nx= i+dir[2*k];
                    int ny= j+dir[2*k+1];
                    dfs(board,vis,nx,ny);
                }
            }else {
                board[i][j]=c+'0';
                return;

            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
        dfs(board,vis,click[0],click[1]);
        return board;
            
        }
};
