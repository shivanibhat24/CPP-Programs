class Solution {
public:
    int largestVariance(string s) {
        int mn[26][26] , mn2[26][26] = {0}, ret = 0 , cnt[26] = {0};
        memset(mn,0x3f,sizeof mn);
        for(char c : s)
        {
            const int x = c - 'a';
            for(int i = 0 ; i < 26 ; i++)
            {
                mn[i][x] = min(mn[i][x],mn2[i][x]);
            }
            cnt[x]++;
            for(int i = 0 ; i < 26 ; i++)
            {
                ret = max({ret,cnt[x] - cnt[i] - mn[x][i],-mn2[i][x] - cnt[x] + cnt[i]});
                mn2[i][x] = min(mn2[i][x], cnt[i] - cnt[x]);
            }
        }
        return ret;
    }
};
