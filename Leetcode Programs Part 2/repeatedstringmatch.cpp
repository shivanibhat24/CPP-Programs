class Solution {
    vector<int> l(string &b){
        int i = 0;
        int j = 1;
        int n = b.size();
        vector<int> v(n,0);

        while(j<n){
            if(b[i]==b[j])
            {
                v[j]=i+1;
                i++;j++;
            }else{
                if(!i) j++;
                else i = v[i-1];
            }
        }
        return v;
    }

    bool kmp(string &a, string &b){
        int i = 0;
        int j = 0;
        vector<int>lps=l(b);

        while(i<a.size()){
        if(a[i]==b[j]){
        i++,j++;
        if(b.size()==j) return 1;
        }
        else{
            if(!j) i++;
            else j = lps[j-1];
            }
        }

        return 0;
    }
public:
    int repeatedStringMatch(string a, string b) {
        if(a==b) return 1;

        int ans = 1;
        string t = a;
        int as = a.size();
        int bs = b.size();
        while(as<bs){
            t += a;
            ans++;
            as = t.size();
        }

        if(kmp(t,b)){
            return ans;
        }
        t+=a;
        ans++;
        if(kmp(t,b)){
            return ans;
        }
        return -1;
    }
};
