class Solution {
public:
int get_depth(int x)
{
    int depth = 0;
    while(x) x>>=1,depth++;
    return depth;
}
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {        
        vector<int> ans;
        for(auto& q:queries){
            int u = q[0],v=q[1],dist = 0;
            int depth_u = get_depth(u),depth_v=get_depth(v);
            while(depth_u<depth_v)
            {
                v>>=1;
                depth_v--;
                dist++;
            }
            while(depth_v<depth_u)
            {
                u>>=1;
                depth_u--;
                dist++;
            }
            while(u!=v)
            {
                u>>=1;
                v>>=1;
                dist+=2;
            }
            ans.push_back(dist+1);
        }
        return ans;
    }
};
