class Solution
{

public:

    int islandPerimeter(vector<vector<int>>& grid)
    {
        int land = 0;
        int adjacent = 0;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                    continue;

                land++;

                if (i > 0 && grid[i - 1][j] == 1)
                    adjacent++;

                if (j > 0 && grid[i][j - 1] == 1)
                    adjacent++;
            }
        }

        return 4 * land - 2 * adjacent;
    }

};
