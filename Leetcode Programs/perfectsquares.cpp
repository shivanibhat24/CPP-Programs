class Solution {
public:
    int numSquares(int n) {
        int idx=sqrt(n);
        if(idx*idx==n){
            return 1;
        }
        while(n%4==0){
            n/=4;
        }
        if(n%8==7){
            return 4;
        }
        for(int i=1;i<sqrt(n);i++){
            int s2=i*i;
            int s=sqrt(n-s2);
            if(s*s==n-s2){
                return 2;
            }
        }
        return 3;
    }
};
