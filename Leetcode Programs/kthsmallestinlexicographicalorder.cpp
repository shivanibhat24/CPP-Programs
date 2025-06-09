class Solution {
public:
    int n, d;
    vector<int> noPer;
    bool isPerfect;
    long long perfect[10] = {1,         11,          111,     1111,
                             11111,     111111,      1111111, 11111111,
                             111111111, 1111111111LL};
    long long tens[11] = {1,         10,         100,          1000,
                          10000,     100000,     1000000,      10000000,
                          100000000, 1000000000, 10000000000LL};
    int cntNodes(long long x) {
        int dx=log10(x), hx=d-dx;     
        hx-=(x>noPer[dx]); 
        if (isPerfect ||x != noPer[dx]) {
            return perfect[hx];
        }
        long long curr = x;
        long long next = x+1;
        int cnt = 0;
        while (curr <= n) {
            cnt+= min(n + 1LL, next)-curr; 
            curr*= 10;  
            next*= 10;
        }
        return cnt;
    }
    int findKthNumber(int n, int k) {
        this->n = n;
        d=log10(n);
        isPerfect=(n+1==tens[d+1]);
        noPer.assign(d+1, INT_MAX);
        if (!isPerfect){
            for (int i=0, z=n; i <= d; z/=10, i++) 
                noPer[d-i]=z;
        }
        int curr=1;
        k--; 
        while (k > 0) {
            int num=cntNodes(curr); 
            if (num <= k) {
                curr++;
                k -= num;
            } 
            else {
                curr*=10; 
                k--;
            }
        }
        return curr;
    }
    void print(auto& c){
        for(auto x: c)cout<<x<<", "; cout<<endl;
    }
};
