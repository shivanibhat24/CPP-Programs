class Solution {
private:
    void cyclicSort(vector<int>& nums)
    {
        int i=0;
        while(i<nums.size())
        {
            if(nums[i] != nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
            else
                i++;
        }
    }
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2,-1); 
        cyclicSort(nums);
        for(int i=0; i<nums.size(); i++)
            if(nums[i] != i+1)
            {
                ans[1] = i+1;
                ans[0] = nums[i];
            }
        return ans;
    }
};
