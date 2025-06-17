class Solution {
    vector<vector<double>> dp;
public:
    double soupServings(int n) {        
        int m ;
        if(n %25 == 0) m = n/25;
        else m = n/25 +1 ;
        if( m >= 200) return 1 ;
        dp.resize(m+1 , vector<double>(m+1 , -1 ));
        return prob( m , m );
    }
    double prob( int a , int b){   
        if( a == 0 && b > 0) return 1; 
        if( a == 0 && b == 0) return 0.5 ;
        if( a > 0 && b == 0) return 0;
        if( dp[a][b] != -1) return dp[a][b];
        double ans = 0;
        for( int servings = 4 ; servings > 0 ; servings--){
            ans += 0.25 * prob( max(0,a-servings) , max(0 , b - 4 + servings));
        }
        return dp[a][b] = ans ;
    }
};
