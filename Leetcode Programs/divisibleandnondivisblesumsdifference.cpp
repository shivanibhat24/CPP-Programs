class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum=n*(n+1)/2;
        int num2M=m*(n/m)*(n/m+1);
        return sum-num2M;        
    }
};
