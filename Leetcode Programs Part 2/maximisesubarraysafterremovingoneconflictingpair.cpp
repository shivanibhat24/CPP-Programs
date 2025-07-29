class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        static long long mores[100001];
        static int conflictsLeft[100001][2]; 
        memset(mores,0,sizeof(mores[0])*(n+1));
        memset(conflictsLeft,0,sizeof(conflictsLeft[0])*(n+1));
        for(auto &v:conflictingPairs){
            int v1=v[0],v2=v[1];
            if(v1<v2) swap(v1,v2);
            if(conflictsLeft[v1][1]>=v2) continue;
            const int tmp=conflictsLeft[v1][0];
            if(tmp<v2){
                conflictsLeft[v1][1]=tmp;
                conflictsLeft[v1][0]=v2;
            }else{
                conflictsLeft[v1][1]=v2;
            }
        }
        long long rtv0=0,more=0; 
        int banned1=0,banned2=0; 
        for(int i=1,j=1;j<=n;++j){
            const int n=conflictsLeft[j][0];
            if(banned2<n){
                if(banned1<n){
                    banned2=max(banned1,conflictsLeft[j][1]);
                    banned1=n;
                    if(banned1>=i) i=banned1+1;
                }else{
                    banned2=n;
                }
            }
            rtv0+=j-(i-1);
            if(banned1!=banned2) more=max(more,mores[banned1]+=banned1-banned2);
        }
        return rtv0+more;
    }
};
