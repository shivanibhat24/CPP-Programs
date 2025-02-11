class Solution {
public:
    int fun(vector<int>&price,int n,vector<int>&need,vector<vector<int>>& special,int s,map<vector<int>,int>&mp){
        if(mp.find(need)!=mp.end()){
            return mp[need];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=need[i]*price[i];
        }
        for(int i=0;i<s;i++){
            bool isvalid=true;
            for(int j=0;j<n;j++){
                if(need[j]<special[i][j]){
                    isvalid=false;
                    break;
                }
            }
            if(isvalid){
                for(int j=0;j<n;j++){
                    need[j]-=special[i][j];
                }
                int temp=fun(price,n,need,special,s,mp);
                if(temp!=INT_MAX){
                    ans=min(ans,special[i][n]+temp);
                }
                for(int j=0;j<n;j++){
                    need[j]+=special[i][j];
                }
            }
        }
        return mp[need]=ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n=price.size();
        int s=special.size();
        map<vector<int>,int>mp;
        return fun(price,n,needs,special,s,mp);
    }
};
