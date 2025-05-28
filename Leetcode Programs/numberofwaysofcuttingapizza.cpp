class Solution {
private:
    int recursion(int i , int j , int k){
        if(apple[i][j] < k) return 0;
        if(k == 1){
            if(apple[i][j] >= 1) return 1;
            return 0;
        }
        int ans = 0;
        for(int h = i + 1 ; h < m ; ++h){
            int lowerSlice = apple[h][j];
            int upperSlice = apple[i][j] - lowerSlice;
            if(upperSlice >= 1 && lowerSlice >= k-1){
                ans = ((ans%mod) + (recursion(h , j , k-1)%mod))%mod;
            }
        }
        for(int v = j + 1 ; v < n ; ++v){
            int rightSlice = apple[i][v];
            int leftSlice = apple[i][j] - rightSlice;
            if(leftSlice >= 1 && rightSlice >= k - 1){
                ans = ((ans%mod) + (recursion(i , v , k-1)%mod))%mod;
            }
        }
        return ans;
    }
    int memoization(int i , int j , int k){
        if(apple[i][j] < k) return 0;
        if(k == 1){
            if(apple[i][j] >= 1) return 1;
            return 0;
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int ans = 0;
        for(int h = i + 1 ; h < m ; ++h){
            int lowerSlice = apple[h][j];
            int upperSlice = apple[i][j] - lowerSlice;
            if(upperSlice >= 1 && lowerSlice >= k-1){
                ans = ((ans%mod) + (memoization(h , j , k-1)%mod))%mod;
            }
        }
        for(int v = j + 1 ; v < n ; ++v){
            int rightSlice = apple[i][v];
            int leftSlice = apple[i][j] - rightSlice;

            if(leftSlice >= 1 && rightSlice >= k - 1){
                ans = ((ans%mod) + (memoization(i , v , k-1)%mod))%mod;
            }
        }
        return dp[i][j][k] = ans;
    }
    int tabulation(int K){
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(apple[i][j] >= 1) {
                    dp[i][j][1] = 1;
                }
            }
        }
        for(int i = m-1 ; i >= 0 ; --i){
            for(int j = n-1 ; j >= 0 ; --j){
                for(int k = 2 ; k <= K ; ++k){
                    int ans = 0;
                    for(int h = i + 1 ; h < m ; ++h){
                        int lowerSlice = apple[h][j];
                        int upperSlice = apple[i][j] - lowerSlice;
                        if(upperSlice >= 1 && lowerSlice >= k-1){
                            ans = ((ans%mod) + (dp[h][j][k-1]%mod))%mod;
                        }
                    }
                    for(int v = j + 1 ; v < n ; ++v){
                        int rightSlice = apple[i][v];
                        int leftSlice = apple[i][j] - rightSlice;
                        if(leftSlice >= 1 && rightSlice >= k - 1){
                            ans = ((ans%mod) + (dp[i][v][k-1]%mod))%mod;
                        }
                    }

                    dp[i][j][k] = ans;
                }
            }
        }
        return dp[0][0][K];
    }
public:
    int m , n;
    int apple[55][55];
    int dp[55][55][15];
    int mod = 1e9+7;
    int ways(vector<string>& pizza, int k) {
        m = pizza.size();
        n = pizza[0].size();
        memset(apple , 0 , sizeof(apple));
        for(int i = m-1 ; i >= 0 ; --i){
            for(int j = n-1 ; j >= 0 ; --j){               
                apple[i][j] = apple[i][j+1];                
                for(int l = i ; l < m ; ++l){
                    if(pizza[l][j] == 'A'){
                        apple[i][j]++;
                    }
                }
            }
        }
        memset(dp , 0 , sizeof(dp));
        return tabulation(k);
    }
};
