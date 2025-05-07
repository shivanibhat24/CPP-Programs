class Solution {
public:
    long long sumScores(string s) {
        long long val=s.length();
        vector<long long>z(s.length(),0);
        int l,r;
        l=0,r=0;
        for(int i=1;i<s.length();i++)
        {
            if(i>r)
            {
                l=i;
                r=i;
                while(r<s.length() && s[r]==s[r-l])
                r++;
                r--;
                z[i]=r-l+1;
            }
            else
            {
                int x=i-l;
                if(z[x]<r-i+1)
                {
                    z[i]=z[x];
                }
                else
                {
                    l=i;
                    while(r<s.length() && s[r]==s[r-l])
                    r++;
                    r--;
                    z[i]=r-l+1;
                }
            }
        }
        for(int i=0;i<z.size();i++)
        {
            val+=z[i];
        }
        return val;
    }
};
