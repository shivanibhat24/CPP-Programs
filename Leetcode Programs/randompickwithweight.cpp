class Solution {
public:
    Solution(vector<int>& w) {
        int runningSum = 0;
        for (int weight : w) {
            runningSum += weight;
            runningSums.push_back(runningSum);
        }
        totalSum = runningSum;
    }    
    int pickIndex() {
        int target = rand() % totalSum + 1;
        int low = 0, high = runningSums.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (target > runningSums[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
private:
    vector<int> runningSums;
    int totalSum;
};
