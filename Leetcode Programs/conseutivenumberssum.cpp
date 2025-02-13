class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int i = 1; 
        long long j = 0;
        int ans = 0;  
        while (j < n) {
            if ((n - j) % i == 0) {
                ans++; 
                cout << i << endl; 
            }
                        j += i;  
            i++;     
        }
        return ans;
    }
};
