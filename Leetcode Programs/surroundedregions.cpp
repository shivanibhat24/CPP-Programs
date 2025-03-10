class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        board[i][j] = '#'; 
        int x[] = {1, -1, 0, 0};
        int y[] = {0, 0, 1, -1};
        for (int k = 0; k < 4; k++) {
            int ni = i + x[k], nj = j + y[k];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 'O') {
                dfs(ni, nj, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') dfs(0, i, board);
            if (board[m - 1][i] == 'O') dfs(m - 1, i, board);
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][n - 1] == 'O') dfs(i, n - 1, board);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};
