class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {        
        vector<int> count(100001), freq(100001);
        int n = nums.size(), a,c,d, res=0;        
        for(int i=1 ; i<=n ; i++){
            a = nums[i-1];
            freq[count[a]]--;
            c = ++count[a];
            freq[count[a]]++;
            if(c*freq[c] == i && i<n)     res = i+1;
            d = i - c*freq[c];
            if((d == 1 || d == c+1) && freq[d] == 1)      res = i;
        }        
        return res;
    }
};
