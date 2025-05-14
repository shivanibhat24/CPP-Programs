class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int j=n-1;
        int mid=((n+1)/2)-1;
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            if(i%2==0) res[i]=nums[mid--];
            else res[i]=nums[j--];
        }
        nums=res;
    }
};
