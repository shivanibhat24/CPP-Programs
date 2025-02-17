class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int ED[n+1][m+1];
        for(int i=0; i<=n; i++) ED[i][0] = i;
        for(int j=0; j<=m; j++) ED[0][j] = j;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                ED[i][j] = min(ED[i-1][j]+1, ED[i][j-1]+1);
                ED[i][j] = min(ED[i][j], ED[i-1][j-1] + (word1[i-1] != word2[j-1]) );
            }
        }
        return ED[n][m];
    }
};
