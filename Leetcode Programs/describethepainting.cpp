#define ll long long
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        ll mini = 1e18;
        ll maxi = -1e18;
        for(auto &v : segments){
            maxi = max(maxi,(ll)v[1]);
            mini = min(mini,(ll)v[0]);
        }
        vector<ll> sweep(maxi+2,0);
        vector<ll> breakpt(maxi+2,0);
        for(auto &v : segments){
            sweep[v[0]] += v[2];
            sweep[v[1]] -= v[2];
            breakpt[v[0]] = 1;
            breakpt[v[1]] = 1;
        }
        ll prev = -1;
        ll currsum = 0;
        vector<vector<ll>> ans;
        for(int i=mini;i<= maxi;i++){
            if(prev==-1){
                prev = i;
            }
            currsum += sweep[i];
            if(currsum!=0){
                if(breakpt[i+1]){
                    ans.push_back({prev,i+1,currsum});
                    prev = i+1;
                }
            }
            else{
                prev = i+1;
            }
        }
        return ans;
    }
};
