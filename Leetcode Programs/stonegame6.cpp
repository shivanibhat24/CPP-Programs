class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<int> sums(n,0);
        int diff = 0;
        for(int i=0;i<n;i++){
            sums[i] += (aliceValues[i] + bobValues[i]);
            diff -= bobValues[i];
        }
        sort(sums.begin(),sums.end());
        for (int i = n - 1; i >= 0; i -= 2)
            diff += sums[i];        
        return diff == 0 ? 0 : diff > 0 ? 1 : -1;
    }
};
