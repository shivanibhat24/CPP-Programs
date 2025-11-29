class Solution {
private:
    const int MOD = 1e9 + 7;

    int maxSubarraySumCircular(const vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN, minSum = INT_MAX;
        int totalSum = 0, currentMax = 0, currentMin = 0;

        for (const int& num : nums) {
            currentMax = max(currentMax + num, num);
            maxSum = max(maxSum, currentMax);
            
            currentMin = min(currentMin + num, num);
            minSum = min(minSum, currentMin);
            
            totalSum += num;
        }

        // Handle case where all elements are negative
        if (maxSum <= 0) return *max_element(nums.begin(), nums.end());

        return max(maxSum, totalSum - minSum);
    }

    int maxSubarraySumCircularDouble(const vector<int>& nums) {
        vector<int> doubledArray(nums.begin(), nums.end());
        doubledArray.insert(doubledArray.end(), nums.begin(), nums.end());

        long long maxSum = 0, currentSum = 0;

        for (const int& num : doubledArray) {
            currentSum = max(currentSum + num, (long long)num);
            maxSum = max(maxSum, currentSum);

            if (currentSum < 0) currentSum = 0;
        }

        return maxSum % MOD;
    }

public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0LL);

        if (k == 1) {
            // Find the maximum subarray sum for a single array
            int maxSingle = 0, currentSum = 0;
            for (const int& num : arr) {
                currentSum = max(currentSum + num, num);
                maxSingle = max(maxSingle, currentSum);
            }
            return maxSingle;
        } else {
            if (totalSum >= 0) {
                int maxSubSum = maxSubarraySumCircularDouble(arr);
                long long result = maxSubSum;
                result = (result + 1LL * (totalSum % MOD) * ((k - 2) % MOD)) % MOD;
                return int(result);
            } else {
                int maxSubSum = maxSubarraySumCircular(arr);
                return max(maxSubSum, 0);
            }
        }
    }
};
