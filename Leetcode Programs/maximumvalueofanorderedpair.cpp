class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long highest = 0; 
        long long highest_diff = 0; 
        long long answer = 0;
        for(long long num : nums) { 
            answer = max( answer , highest_diff * num); 
            highest_diff = max(highest_diff, highest - num);
            highest = max(highest, num);
        }
        return answer;
    }
};
