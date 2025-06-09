class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();        
        vector<int> leftBoundary(n, -1);
        vector<int> rightBoundary(n, n); 
        stack<int> leftStack;
        stack<int> rightStack;
        for (int i = n - 1; i >= 0; i--) {
            while (!leftStack.empty() && nums[leftStack.top()] > nums[i]) {
                leftBoundary[leftStack.top()] = i;
                leftStack.pop();
            }
            leftStack.push(i);
        }
        for (int i = 0; i < n; i++) {
            while (!rightStack.empty() && nums[rightStack.top()] > nums[i]) {
                rightBoundary[rightStack.top()] = i; 
                rightStack.pop();
            }
            rightStack.push(i);
        }        
        int maxScore = 0;
        for (int i = 0; i < n; i++) {
            if (leftBoundary[i] < k && rightBoundary[i] > k) {
                int subarrayScore = nums[i] * (rightBoundary[i] - leftBoundary[i] - 1);
                maxScore = max(maxScore, subarrayScore);
            }
        }        
        return maxScore; 
    }
};
