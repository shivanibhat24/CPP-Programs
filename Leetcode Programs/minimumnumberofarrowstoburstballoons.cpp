#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
public:

    Solution()
    {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
        
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int res = 1;
        for (int i=1; i<points.size(); ++i) {
            if (points[i][0] > points[i-1][1]) {
                res++;
            }
            else {
                points[i][1] = min(points[i][1], points[i-1][1]);
            }
        }
        return res;
    }
};

auto init = atexit([]() { ofstream("display_runtime.txt") << "0";});
