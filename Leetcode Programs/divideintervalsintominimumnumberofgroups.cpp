class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        const int n = 1e6+2;
        int sum=0,res=0;
        int cnt[n]={0};
        for(auto& i:intervals){
            int l = i[0];
            int r = i[1];
            cnt[l]++;
            cnt[r+1]--;
        }        
        for(auto& c:cnt){
            sum+=c;
            res = max(res,sum);
        }
        return res;
    }
};
