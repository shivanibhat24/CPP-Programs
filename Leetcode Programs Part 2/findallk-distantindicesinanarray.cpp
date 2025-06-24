class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();
        int start = 0;
        for(int i=0;i<n;i++){
            if (nums[i] == key){
                int left = max(0,i-k);
                int right = min(n-1,i+k);
                while(start<=right){
                    if (start>=left) ans.push_back(start);
                    start++;
                }
            }
        }
        return ans;
    }
};
