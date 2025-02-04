class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int r[9] = {0}, c[9] = {0}, b[9] = {0};
        vector<pair<int,int>> emp;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') emp.push_back({i,j});
                else {
                    int d = board[i][j]-'0', m = 1 << d;
                    r[i] |= m; c[j] |= m; b[(i/3)*3+j/3] |= m;
                }
            }
        }
        dfs(board, emp, r, c, b);
    }
    bool dfs(vector<vector<char>>& board, vector<pair<int,int>>& emp, int r[9], int c[9], int b[9]){
        if(emp.empty()) return true;
        int best = -1, avail = 0, cnt = 10;
        for(int i = 0; i < emp.size(); i++){
            int x = emp[i].first, y = emp[i].second, box = (x/3)*3 + y/3;
            int a = ~(r[x] | c[y] | b[box]) & 0x3FE;
            int bits = __builtin_popcount(a);
            if(bits < cnt){ cnt = bits; best = i; avail = a; if(cnt == 1) break; }
        }
        if(cnt == 0) return false;
        int x = emp[best].first, y = emp[best].second, box = (x/3)*3 + y/3;
        pair<int,int> cell = emp[best];
        swap(emp[best], emp.back());
        emp.pop_back();
        while(avail){
            int low = avail & -avail; avail -= low;
            int d = __builtin_ctz(low);
            board[x][y] = d + '0';
            r[x] |= low; c[y] |= low; b[box] |= low;
            if(dfs(board, emp, r, c, b)) return true;
            r[x] ^= low; c[y] ^= low; b[box] ^= low;
        }
        board[x][y] = '.';
        emp.push_back(cell);
        swap(emp[best], emp.back());
        return false;
    }
};
