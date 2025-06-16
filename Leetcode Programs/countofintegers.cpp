class Solution {
    public:
        string n;
        int min;
        int max;
        int memo[23][2][220];
        int kMod = 1'000'000'007;
        int count(string num1, string num2, int min_sum, int max_sum) {
            this->min=min_sum;
            this->max=max_sum;
             return (solve(num2) - solve(minusOne(num1)) + kMod) % kMod;
        }
        int solve(string _n){
            this->n=_n;
            memset(memo, -1, sizeof(memo));
            return dp(0,1,0);
        }
        int dp(int index, int last, int sum){
            if(index==n.size()){
                if(sum>=min && sum<=max) return 1;
                return 0;
            }
            if(memo[index][last][sum]!=-1) return memo[index][last][sum];
            int till = last?n[index]-'0':9;
            int ans=0;
            for(int digit=0; digit<=till; digit++){
                ans+=dp(index+1, last && digit==till, sum+digit);
               ans %= kMod;
            }
            return memo[index][last][sum]= ans;
        }
        string minusOne(string s){
            int i= s.size()-1;
            while(i>=0 && s[i]=='0'){
                s[i]='9';
                i--;
            }           
            s[i]--;
            return s;
        }
};
