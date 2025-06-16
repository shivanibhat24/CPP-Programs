class Solution {
public:
    int dis[501][501]; 
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size ();        
        memset(dis, -1, sizeof(dis[0])*points.size()+1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int dist = my_distance(points, i, j); 
                dis [i][j] = dist;
                dis [j][i] = dist;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            auto &len = dis[i];
            ranges::sort(len, len+n);
            int last = len[0], count = 1;
            for (int j = 0; j < n; j++)
            {
                if (len[j] == -1) {
                    res += count * (count - 1);
                    count = 1;
                    continue;
                }
                if (len[j] == last)
                    count++;
                else {  
                    res += count * (count - 1);
                    count = 1;
                    last = len[j];
                }
            }
            res += count * (count - 1);
        }
        return res;
    }
    inline int my_distance(vector<vector<int>>& points, int i, int j)
    {
        vector<int>& a = points[i];
        vector<int>& b = points[j];
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);  
    }
};
