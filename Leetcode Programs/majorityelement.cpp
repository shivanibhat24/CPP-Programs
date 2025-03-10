class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size(),count=0,element,ans;
        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                count=1;
                element=nums[i];
            }
            else
            {
                if(element==nums[i])
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }
        count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==element)
            {
                count++;
            }
        }
        if(count<n/2)
        {
            ans=element;
        }
        return ans;
    }
};
