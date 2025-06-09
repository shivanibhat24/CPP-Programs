class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int left = 0, maxSum = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (i - left > k) left++;
            int currentSum = nums[i] + ((left != i && nums[left] > 0) ? nums[left] : 0);
            nums[i] = currentSum;
            while (left < i && nums[left] <= currentSum) left++;
            for (int j = i - 1; j >= left && nums[j] < currentSum; j--)
                nums[j] = currentSum;
            maxSum = std::max(maxSum, currentSum);
        }
        return maxSum;
    }
};
