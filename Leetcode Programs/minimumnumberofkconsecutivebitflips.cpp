class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flip=0;
        vector<bool>isflipped(n,false);
        int flipcountfrompassforcurri=0;
        for(int i=0;i<n;i++){
            if(i>=k && isflipped[i-k] == true){
                flipcountfrompassforcurri--;
            }
            if(flipcountfrompassforcurri%2 ==nums[i]){ 
            if(i+k > n )return -1;
                flipcountfrompassforcurri++;
                isflipped[i]=true;
                flip++;                  
            }
        }
        return flip;        
    }
};
