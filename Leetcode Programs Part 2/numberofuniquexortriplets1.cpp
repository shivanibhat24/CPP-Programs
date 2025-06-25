class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;
        int cnt = 0;
        int temp = n;
        while(temp > 0){
            temp >>= 1;
            cnt++;
        }        
        return pow(2, cnt);
    }
};
