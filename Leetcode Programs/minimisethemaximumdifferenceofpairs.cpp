class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;        
        sort(nums.begin(), nums.end());        
        int minThrehold = 0;
        int maxThrehold = nums[nums.size() - 1] - nums[0];
        while (minThrehold < maxThrehold) {
            int candidateThrehold = minThrehold + (maxThrehold - minThrehold) / 2; 
            int pairs = 0;
            for (int i = 1; i < nums.size(); ++i) {
                if (candidateThrehold >= nums[i] - nums[i - 1]) {
                    ++pairs;
                    ++i; 
                }
            }
            if (pairs >= p) { 
                maxThrehold = candidateThrehold;
            } else { 
                minThrehold = candidateThrehold + 1;
            }
        }
        return minThrehold;
    }
};
