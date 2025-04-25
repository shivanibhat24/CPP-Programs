class Solution {
    vector<int> a;
public:
    Solution(): a(10000, 0){};
    void bt(string &r, int n, int k, int m){
        int t = 0;
        if(n > 1) {
            t = stoi(r.substr(r.length()-n+1, n-1));
        }
        t = t*10;
        for(int i = k-1; i >= 0; --i){
            if(!a[t+i]){
                a[t+i] = 1;
                r += ('0'+i);
                bt(r, n, k, m);
                return;
            }
        }
    }
    string crackSafe(int n, int k) {
        string r(n, '0');
        a[0] = 1;
        bt(r,n,k,pow(k,n));
        return r;
    }
};
