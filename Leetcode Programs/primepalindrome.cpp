class Solution {
public:
    bool isPalindrome(int n) {
        string s = to_string(n);
        string temp = s; reverse(temp.begin() , temp.end()); 
        return s == temp;
    }
    bool isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i <= sqrt(num); i++) 
            if (num % i == 0) return false;
            return true;
        }
    int primePalindrome(int n) {
        for (int i = n; i < 200000000; i++) {
            if (isPalindrome(i) && isPrime(i)) return i; 
        }
        return 1e8;
    }
};
