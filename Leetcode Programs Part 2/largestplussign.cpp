class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        if (mines.size() == n * n)
            return 0;
        bool field[500][500] = {};
        for (const vector<int>& mine : mines)
            field[mine[0]][mine[1]] = true;
        int grid[500][500];
        for (int i = 0; i < n; i++)
        {
            int cur = 0;
            for (int j = 0; j < n; j++)
            {
                grid[i][j] = cur;
                cur = (field[i][j]) ? 0 : cur+1;
            }
            cur = 0;
            for (int j = n-1; j >= 0; j--)
            {
                grid[i][j] = min(grid[i][j], cur);
                cur = (field[i][j]) ? 0 : cur+1;
            }
        }        
        for (const vector<int>& mine : mines)
            grid[mine[0]][mine[1]] = 0;
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            int cur = 0;
            for (int j = 0; j < n; j++)
            {
                grid[j][i] = min(grid[j][i], cur);
                cur = (field[j][i]) ? 0 : cur+1;
            }
            cur = 0;
            for (int j = n-1; j >= 0; j--)
            {
                ret = max(grid[j][i] = min(grid[j][i], cur), ret);
                cur = (field[j][i]) ? 0 : cur+1;
            }
        }
        return ret + 1;
    }
};
