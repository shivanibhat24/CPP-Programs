class Solution {
public: 
    #define ll long long
    bool isPrime(ll n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (ll i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        set<long long,greater<ll>> st;
        for (int i = 0; i < n; i++) {
            for (int len = 1; len <= n - i; len++) {
                string temp = s.substr(i, len);
                long long tempno = stoll(temp);
                if (isPrime(tempno))
                    st.insert(tempno);
            }
        }
        long long ans = 0;
        for (int i = 1; i <= 3; i++) {
            if(st.empty()) break;
            ans += *st.begin();
            st.erase(*st.begin());
        }
        return ans;
    }
};
