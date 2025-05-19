class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long preSumTop = 0;
        for(int i = 0; i < grid[0].size(); i++)
        {
            preSumTop += grid[0][i];
        }
        long long result = LLONG_MAX, sumBottomLeft = 0;
        for(int i = 0; i < grid[0].size(); i++)
        {
            preSumTop -= grid[0][i];
            
            long long robot2 = (preSumTop > sumBottomLeft) ? preSumTop : sumBottomLeft;
            if(result > robot2)
                result = robot2;
            sumBottomLeft += grid[1][i];
        }
        return result;
    }
};
