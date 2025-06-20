class Solution {
public:
    int dp[10][10001];
    int mn=INT_MAX;
    int aux(int ind,int tar,vector<int> &top){
        if(mn!=INT_MAX){if(mn+tar==0&&mn<0)
            mn=tar;}
        if(abs(tar)<abs(mn)){
            
            mn=tar;
        }
        if(tar<0)
        return 0;
        if(tar==0)
        return 1;
        if(ind==top.size())
        return 0;
        if(dp[ind][tar]!=-1)
        return dp[ind][tar];
        int a=aux(ind+1,tar,top);
        
        int b=aux(ind+1,tar-top[ind],top);
        int c=aux(ind+1,tar-2*top[ind],top);
        b=max(b,c);
        return dp[ind][tar]=max(a,b);
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {       
        memset(dp,-1,sizeof(dp));        
        sort(baseCosts.begin(),baseCosts.end()); 
        for(auto it: baseCosts){
            int temp=target-it;
            aux(0,temp,toppingCosts);
        }
        if(mn==INT_MAX)
        return baseCosts[0];
        return target-mn;            
    }
};
