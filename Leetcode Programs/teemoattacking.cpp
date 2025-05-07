class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {        
        if(duration == 0) return 0;
        duration--;
        int prev_l = timeSeries[0];
        int prev_r = timeSeries[0] + duration;
        int n = timeSeries.size();
        int ans = 0;
        for(int i:timeSeries){
            if(i <= prev_r){
                prev_r = i+duration;
            }
            else{
                ans += prev_r-prev_l+1;
                prev_l = i;
                prev_r = i+duration;
            }
        }
        ans += prev_r-prev_l+1;
        return ans;
    }
};
