class DSU {
    private:
    vector<int> vec , wt;
    const int mod = 1e9+7;
    public:
    DSU(int n){
        vec.resize(n);
        wt.resize(n);
        for(int i = 0 ; i < n ; i++){
            vec[i] = i;
            wt[i] = 1;
        }
    }
    pair<int,int> find(int n){
        if(n == 0 || vec[n] == n) return {n , 1};
        auto val = find(vec[n]);
        wt[n] = ((long)(wt[n] % mod) * (val.second) % mod) % mod;
        vec[n] = val.first;
        return {val.first , wt[n]};
    }
    void union_(int s , int t , int c){
        vec[t] = s, wt[t] = c;
    }
};
class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int N = conversions.size() + 1;
        DSU dsu(N);
        for(auto & i : conversions){
            dsu.union_(i[0], i[1] , i[2]);
        }
        vector<int> ans;
        for(int i = 0 ; i < N ; i++){
            ans.push_back(dsu.find(i).second);
        }
        return ans;
    }
};
