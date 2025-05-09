static const int MOD = 1e9+7;
long long modexp(long long b, long long e=MOD-2){
    long long res=1;
    while(e){
        if(e&1) res = res*b % MOD;
        b = b*b % MOD;
        e >>= 1;
    }
    return res;
}
int add(int a,int b){ a+=b; if(a>=MOD) a-=MOD; return a; }
int mul(long long a,long long b){ return (int)( (a*b)%MOD ); }
int countBalanced(const string &num){
    int N = num.size();
    vector<int> freq(10,0);
    int totalSum = 0;
    for(char c: num){
        int d = c-'0';
        freq[d]++;
        totalSum += d;
    }
    if(totalSum & 1) return 0;
    int halfSum = totalSum/2;
    int E = (N+1)/2;  
    int O = N/2;
    int M = N; 
    vector<long long> fact(M+1,1), invf(M+1,1);
    for(int i=1;i<=M;i++){
        fact[i] = fact[i-1]*i % MOD;
    }
    invf[M] = modexp(fact[M]);
    for(int i=M;i>0;i--){
        invf[i-1] = invf[i]*i % MOD;
    }
    static int dp[11][51][4501];
    for(int d=0;d<=10;d++)
      for(int e=0;e<=E;e++)
        for(int s=0;s<=halfSum;s++)
          dp[d][e][s] = 0;
    dp[0][E][halfSum] = 1;
    for(int d=0; d<10; d++){
        int f = freq[d];
        for(int e=0; e<=E; e++){
            for(int s=0; s<=halfSum; s++){
                int ways = dp[d][e][s];
                if(!ways) continue;
                for(int x=0; x<=f && x<=e; x++){
                    int y = f - x;
                    if(y > O) continue;
                    int ns = s - d*x;
                    if(ns < 0) break; 
                    int addWays = mul(ways,
                               mul(invf[x], invf[y])
                             );
                    dp[d+1][e-x][ns] = add(dp[d+1][e-x][ns], addWays);
                }
            }
        }
    }
    int invWeightSum = dp[10][0][0];
    int result = mul( mul(fact[E], fact[O]), invWeightSum );
    return result;
}
class Solution {
public:
    int countBalancedPermutations(string num) {
        return countBalanced(num);
    }
};
