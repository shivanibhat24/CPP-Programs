class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xOr=0;
        for(auto x:nums){
            xOr^=x;
        }
        int check=0;
        for(int i=0;i<32;i++){
            if((1LL<<i)&xOr){
                check=i;
                break;
            }
        }
        int ans1=0;
        for(auto x:nums){
            if(x&(1LL<<check)){
                ans1^=x;
            }
        }
        return {ans1,ans1^xOr};
    }
};
