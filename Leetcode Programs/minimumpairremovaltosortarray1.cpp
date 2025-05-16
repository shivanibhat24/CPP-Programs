class Solution {
public:
    bool isNumsSorted(vector<int>& nums)
    {
        for (int k = 0; k < nums.size() - 1; k++)
        {
            if (nums[k] > nums[k+1])
            {
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int minimum = 0;
        int temp = 0;
        int temp_id = 0;

        while (!isNumsSorted(nums))
        {
            temp = INT_MAX;
            temp_id = 0;
            minimum++;
            for (int j = 0; j < nums.size() - 1; j++)
            {
                if (nums[j] + nums[j + 1] < temp)
                {
                    temp = nums[j] + nums[j + 1];
                    temp_id = j;
                }
            }
            nums[temp_id] += nums[temp_id + 1];
            nums.erase(nums.begin() + (temp_id + 1));
        }
        return minimum;
    }
};
