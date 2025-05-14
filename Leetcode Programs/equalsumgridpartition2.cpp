class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += grid[i][j];
            }
        }
        long long s1 = 0;
        long long s2 = sum;
        vector<bool> h1(100001, false);
        h1[0] = true;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                s1 += grid[i][j];
                s2 -= grid[i][j];
                h1[grid[i][j]] = true;
            }
            long long dif = s1 - s2;
            if(m==1){
                if(dif==0||grid[0][0]==dif||grid[i][0]==dif) return true;
            }else if (i == 0) {
                if (dif == 0 || grid[i][0] == dif || grid[i][m - 1] == dif)
                    return true;
            } else if (dif >= 0 && dif <= 100000 && h1[dif])
                return true;
        }
        s1 = sum;
        s2 = 0;
        vector<bool> h2(100001, false);
        h2[0] = true;
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < m; j++) {
                s2 += grid[i][j];
                s1 -= grid[i][j];
                h2[grid[i][j]] = true;
            }
            long long dif = s2 - s1;
            if(m==1){
                if(dif==0||grid[n-1][0]==dif||grid[i][0]==dif) return true;
            }else if (i == n - 1) {
                if (dif == 0 || grid[i][0] == dif || grid[i][m - 1] == dif)
                    return true;
            } else if (dif >= 0 && dif <= 100000 && h2[dif])
                return true;
        }
        s1 = 0;
        s2 = sum;
        vector<bool> h3(100001, false);
        h3[0] = true;
        for (int j = 0; j < m - 1; j++) {
            for (int i = 0; i < n; i++) {
                s1 += grid[i][j];
                s2 -= grid[i][j];
                h3[grid[i][j]] = true;
            }
            long long dif = s1 - s2;
            if(n==1){
                if(dif==0||grid[0][0]==dif||grid[0][j]==dif) return true;
            }else if (j == 0) {
                if (dif == 0 || grid[0][j] == dif || grid[n - 1][j] == dif)
                    return true;
            } else if (dif >= 0 && dif <= 100000 && h3[dif])
                return true;
        }
        s1 = sum;
        s2 = 0;
        vector<bool> h4(100001, false);
        h4[0] = true;
        for (int j = m - 1; j > 0; j--) {
            for (int i = 0; i < n; i++) {
                s2 += grid[i][j];
                s1 -= grid[i][j];
                h4[grid[i][j]] = true;
            }
            long long dif = s2 - s1;
            if(n==1){
                if(dif==0||grid[0][m-1]==dif||grid[0][j]==dif) return true;
            } else if (j == m-1) {
                if (dif == 0 || grid[0][j] == dif || grid[n - 1][j] == dif)
                    return true;
            } else if (dif >= 0 && dif <= 100000 && h4[dif])
                return true;
        }
        return false;
    }
};
