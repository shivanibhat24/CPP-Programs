class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) 
    {
        vector<pair<int,int>> res;
        res.push_back({1,0});
        for(auto& r : restrictions) res.push_back({r[0], r[1]});
        if(res.back().first != n) res.push_back({n, n-1});        
        sort(res.begin(), res.end());
        int m = res.size();
        for(int i = 1; i < m; i++)
        {
            int x = res[i].first;
            int prev_x = res[i-1].first;
            int prev_h = res[i-1].second;
            res[i].second = min(res[i].second, prev_h + (x - prev_x));
        }
        for(int i = m - 2; i >= 0; i--)
        {
            int x = res[i].first;
            int next_x = res[i+1].first;
            int next_h = res[i+1].second;
            res[i].second = min(res[i].second, next_h + (next_x - x));
        }
        int max_ = 0;
        int m_height;
        for(int i = 0; i < m - 1; i++)
        {
            int num1 = res[i].first;
            int height1 = res[i].second;
            int num2 = res[i+1].first;
            int height2 = res[i+1].second;
            if(height1 < height2)
            {
                num1 += height2 - height1;
                int mid = height2 + (num2 - num1) / 2;
                m_height = max(height2, mid);
                if(max_ < m_height) max_ = m_height;
            }
            else
            {
                num2 -= height1 - height2;
                int mid = height1 + (num2 - num1) / 2;
                m_height = max(height1, mid);
                if(max_ < m_height) max_ = m_height;
            }
        }
        return max_;
    }
};
