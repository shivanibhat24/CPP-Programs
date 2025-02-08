class Solution {
public:
    bool checkPerfectNumber(int n) {
        int sum=0;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                sum=sum+i+(n/i);
            }
        }
        if(sqrt(n)*sqrt(n)==n) sum=sum-sqrt(n);
        sum=sum+1;
        return sum==n;

    }
};
