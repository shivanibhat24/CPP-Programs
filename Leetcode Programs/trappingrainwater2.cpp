class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        int change = 1;
        int oldVal = 0;

        std::vector<vector<int>> waterStored (m, std::vector<int> (n, INT_MAX));

        while(change) {
            change = 0;

            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++) {
                    oldVal = waterStored[i][j];
                    if(i==0 || j==0)
                        waterStored[i][j] = heightMap[i][j];
                    else
                        waterStored[i][j] = max(heightMap[i][j], min(waterStored[i][j], min(waterStored[i][j-1], waterStored[i-1][j])));
                    if(oldVal!=waterStored[i][j])
                        change = 1;
                }

            for(int i=m-1; i>=0; i--)
                for(int j=n-1; j>=0; j--) {
                    oldVal = waterStored[i][j];
                    if(i==m-1 || j==n-1)
                        waterStored[i][j] = heightMap[i][j];
                    else
                        waterStored[i][j] = max(heightMap[i][j], min(waterStored[i][j], min(waterStored[i][j+1], waterStored[i+1][j])));
                    if(oldVal!=waterStored[i][j])
                        change = 1;
                }
        }
        
        int ans = 0;
        for(int i=m-1; i>=0; i--)
            for(int j=n-1; j>=0; j--)
                ans += waterStored[i][j]-heightMap[i][j];
        
        return ans;
    }
};
