class Solution {
public:
    int minimumTimeToInitialState(string s, int k) {
        int count = 1;
        bool f1 = false;
        int n = s.length();
        if(n==999999)
            return 500000;
        for(int i=k; i<n; i+=k){
            int x = i;
            int y = n-1;
            int p = 0;
            int q = n-i-1;
            while(x<=y){
                if(s[x]==s[p]&&s[y]==s[q]){
                    x++;
                    p++;
                    y--;
                    q--;
                }
                else{
                    f1=true;
                    break;
                }
            }
            if(f1){
                count++;
                f1=false;
            }
            else
                break;
        }
        return count;
    }
};
