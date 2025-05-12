class Solution {
public:
    int strangePrinter(string s) {
        vector<char>arr;
        for(char c:s){
            if(arr.empty() || c!=arr.back()){
                arr.push_back(c);
            }
        }
        int n=arr.size();     
        vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<int>next(n,-1);
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }        
        unordered_map<char,int>last_seen;
        for(int i=n-1;i>=0;i--){
            char c=arr[i];
            if(last_seen.find(c)!=last_seen.end()){
                next[i]=last_seen[c];
            }
            last_seen[c]=i;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                dp[i][j]=dp[i+1][j] +1;
                char current_char=arr[i];
                int next_pos=next[i];
                while(next_pos!=-1 && next_pos <=j){
                    dp[i][j]=min(dp[i][j],dp[i][next_pos-1] + (next_pos + 1 <=j?dp[next_pos+1][j]:0));
                    next_pos=next[next_pos];
                }
            }
        }
        return dp[0][n-1];
    }
};
