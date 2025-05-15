class Solution {
public:
    int maxCoins(vector<int>& piles) {
    int n=piles.size(), M=0;
        int freq[10001]={0};
        #pragma unroll
        for(int x: piles){
            freq[x]++;
            M=max(M, x);
        }
        int ans=0, count=0, x;
        bool alice=0;
        #pragma unroll
        for(x=M; count<n/3; x--){
            if (freq[x]>0){
                int f=freq[x]+alice;
                int f0=f>>1;
                count+=f0;
                ans+=f0*x;
                alice=(f&1)?1:0;
            }
        }
        ans-=(count-n/3)*(x+1);
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
