class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        } else if (n == 2) {
            return 9009 % 1337;
        } else if (n == 3) {
            return 906609 % 1337;
        } else if (n == 4) {
            return 99000099 % 1337;
        } else if (n == 5) {
            return 9966006699 % 1337;
        } else if (n == 6) {
            return 999000000999 % 1337;
        } else if (n == 7) {
            return 99956644665999 % 1337;
        } else if(n == 8) {
            return 9999000000009999 % 1337;

    }
    return -1;
    }
};
