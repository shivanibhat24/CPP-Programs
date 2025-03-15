class Solution {
public:
    int minCapability(vector<int> &nums, int k) {
        int left = std::numeric_limits<int>::max();
        int right = std::numeric_limits<int>::min();
        int size = nums.size();

        for (const auto &num : nums) {
            if (num < left) {
                left = num;
            }
            if (num > right) {
                right = num;
            }
        }

        while (left < right) {
            int mid = (left + right) / 2;
            int count = 0;
            int index = 0;
            while (index < size) {
                if (nums[index] <= mid) {
                    count += 1;
                    index += 2;
                } else {
                    index += 1;
                }
            }

            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
