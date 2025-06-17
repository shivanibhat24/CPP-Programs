class Solution {
public:
    int findNthDigit(long n) {
        long d=1;
        long ten=10;
        long numberd=1;
        for(int i=1;i<=n;i++){
            if(i==ten){
                ten*=10;
                numberd++;
            }
            if(d==n){
                long num=i;
                long checkten=ten;
                long t=d+numberd;
                while(i>0){
                    if(d==n){
                        return num/(checkten/10);
                    }
                    d++;
                    num=num%checkten;
                    i/=10;
                    checkten/=10;
                }                            
            }
            if(n>d && n<(d+numberd)){
                
                long num=i;
                long checkten=ten;
                long t=d+numberd;
                while(i>0){
                    if(d==n){
                        return num/(checkten/10);
                    }
                    d++;
                    num=num%(checkten/10);
                    i/=10;
                    checkten/=10;
                }
                
            }
            d+=numberd;
        }
        return -1;
    }
};
