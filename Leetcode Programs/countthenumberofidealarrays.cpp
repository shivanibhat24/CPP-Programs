const int mod=1e9+7, N=10015;
bitset<101> sieve=0;
array<int, 25> prime;
static constexpr void sieve100(){
    if (sieve[0]) return;
    sieve[0]=sieve[1]=1;
    int sz=0;
    for(int p=2; p<10; p++){
        if (!sieve[p]){
            prime[sz++]=p;
            for(int j=p*p ; j<100; j+=p)
                sieve[j]=1;
        }
    }
    for(int i=11; i<100; i+=2)
        if (!sieve[i]) prime[sz++]=i;
}
int C[N][15]={{0}};
static constexpr void Pascal(){
    if (C[0][0]==1) return;
    C[0][0]=1;
    for(int i=1; i<N; i++){
        C[i][0]=1;
        int i0=min(14, i);
        for(int j=1; j<=i0; j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if (C[i][j]>=mod) C[i][j]-=mod;
        }
    }
}
unsigned dp[N];
static constexpr long long factor(int x, const int n){
    if (dp[x]!=0) return dp[x];
    if (x<=1) return dp[x]=1;
    long long cnt=1;
    if (x<100 && !sieve[x])
        return dp[x]=n;
    int x0=x, x_sqrt=sqrt(x);
    int pz=0;
    for(int p: prime){
        if (p>x_sqrt) break;
        if (x0%p!=0) continue;
        int exp=0;
        while(x0%p==0){
            exp++;
            x0/=p;
        }
        if (dp[x0]!=0)
            return dp[x]=C[n-1+exp][exp]*factor(x0, n)%mod;
        else cnt=(cnt*C[n-1+exp][exp])%mod;
    } 
    if (x0>1) {
        cnt=(cnt*n)%mod;
    } 
    return dp[x]=cnt;
}
class Solution {
public:
    static int idealArrays(int n, int maxValue) {
        sieve100();
        Pascal();
        long long ans=0;
        memset(dp, 0, (maxValue+1)*sizeof(unsigned));
        for (int x=1; x<=maxValue; x++) {
            const long long ways=factor(x, n);
            ans=(ans+ways)%mod;
        }
        return ans;
    }
};
