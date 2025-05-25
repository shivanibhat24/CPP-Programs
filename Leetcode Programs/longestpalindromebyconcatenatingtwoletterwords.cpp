class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int counts[26][26];
        memset(counts, 0, sizeof(counts));
        for(auto& it: words)
            counts[it[0]-'a'][it[1]-'a']++;        
        int even_count = 0;
        bool odd_count = false;
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                if(i==j){
                    if(counts[i][j]&1)
                        odd_count = true;
                    even_count += (counts[i][i] >> 1) << 2;
                }
                else {
                    int min_count = min(counts[i][j], counts[j][i]);
                    counts[i][j] -= min_count;
                    counts[j][i] -= min_count;
                    even_count += (min_count * 4); 
                }
            }
        }
        return even_count + 2*odd_count;
    }
};
