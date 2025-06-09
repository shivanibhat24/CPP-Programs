class Solution {
    bool palin(string &x)
    {
        int i=0,j=x.length()-1;
        while(i<j)
        {
            if(x[i]==x[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
public:
    bool checkPartitioning(string s) {
        vector<int> prefixPalin(s.length(),0);
        vector<int> suffixPalin(s.length(),0);
        string x="";
        for(int i=0;i<s.length();i++)
        {
            x+=s[i];
            if(palin(x))
            {
                prefixPalin[i]=1;
            }
        }
        x="";
        for(int i=s.length()-1;i>=0;i--)
        {
            x=s[i]+x;
            if(palin(x))
            {
                suffixPalin[i]=1;
            }
        }
        for(int i=0;i<s.length();i++)
        {
            int i1=i-1,j1=i+1;
            if(i1>=0 && j1<s.length() && prefixPalin[i1] && suffixPalin[j1])
            {
                // cout<<i1<<" "<<j1<<endl;
                return true;
            }
            while(i1>0 && j1<s.length()-1)
            {
                if(s[i1]==s[j1] && prefixPalin[i1-1] && suffixPalin[j1+1])
                {
                    return true;
                }
                else if(s[i1]==s[j1])
                {
                    i1--;
                    j1++;
                }
                else
                {
                    break;
                }
            }
            i1=i,j1=i+1;
            while(i1>0 && j1<s.length()-1)
            {
                if(s[i1]==s[j1] && prefixPalin[i1-1] && suffixPalin[j1+1])
                {
                    return true;
                }
                else if(s[i1]==s[j1])
                {
                    i1--;
                    j1++;
                }
                else
                {
                    break;
                }
            }
        }
        return false;
    }
};
