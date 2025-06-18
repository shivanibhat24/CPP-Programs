class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        int second = -1;        
        vector<int> next(n, n);
        stack<int> stk;
        for(int i = 0; i < n; i++){
           if(nums[i] > maxi){
            second = maxi;
            maxi = nums[i];
           }else if(nums[i] > second){
            second = maxi;
           }
            while(!stk.empty() && nums[i] > nums[stk.top()]){
                next[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }        
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++){
            if(nums[i] == maxi) continue;
            if(nums[i] == second) continue;
            int nx = next[i] + 1;
            while (nx < n && nums[nx] <= nums[i] ) {
                nx = next[nx];
                if(nx < n && nums[nx] <= nums[i]){
                    nx++;
                }
            }
               if(nx < n) ans[i] = nums[nx];
        }        
        return ans;
    }
};
