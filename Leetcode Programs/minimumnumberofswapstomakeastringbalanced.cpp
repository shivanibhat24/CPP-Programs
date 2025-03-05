class Solution {
public:   
    int minSwaps(string s) {
        int si=0;
        for(char ch:s){
            if(ch=='[') ++si;
            else{
                if(si>0) --si;                
            }
        }              
        return (si+1)/2;       
    }
};
