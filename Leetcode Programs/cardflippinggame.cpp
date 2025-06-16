class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int ans=2001;
        int a=2001;
        vector<int>v(2001,0);
        for(int i=0;i<fronts.size();i++){
            if(fronts[i]==backs[i])
            v[fronts[i]]++;
        }
        for(int i=0;i<fronts.size();i++){
            if(fronts[i]!=backs[i]){
                
               if(v[min(fronts[i],backs[i])]==0)
               ans=min(fronts[i],backs[i]);
               else if(v[max(fronts[i],backs[i])]==0)
               ans=max(fronts[i],backs[i]);
               
               a=min(a,ans);
            }
        }        
        if(a==2001)
        return 0;
        else
        return a;
    }
};
