class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> t(query_row+2, vector<double>(query_row+2,0.0));
        t[0][0] = (double)(poured);
        for ( int r = 0; r<=query_row;r++){
            for(int c = 0;c<=r;c++){
                if (t[r][c]>1.0) {
                    t[r+1][c] += (t[r][c]-1.0)/2.0;
                    t[r+1][c+1] += (t[r][c]-1.0)/2.0;
                }
            }
        }
        return min(1.0,t[query_row][query_glass]);
    }
};
