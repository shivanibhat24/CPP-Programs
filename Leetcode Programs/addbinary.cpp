class Solution {
public:
    string addBinary(string a, string b) {
        int m=a.size();
        int n=b.size();
        if (m<n)return addBinary(b,a);
        int c=0;
        string ans="";
        for (int i=1;i<=m;i++)
        {
            int p=(a[m-i]=='1');
            int q=0;
            if (i<=n)q=(b[n-i]=='1');
            int r=p+q+c;
            if(r==3)ans="1"+ans;
            else if(r==2){ans="0"+ans;c=1;}
            else if(r){ans="1"+ans;c=0;}
            else ans="0"+ans;
        }
        if(c)return"1"+ans;
        return ans;
    }
};
