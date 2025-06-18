class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> nge(n);        
        for(int i = 2 * n - 1; i > -1; i--){
            int j = i % n;
            while(!st.empty() && st.top() <= nums[j])
                st.pop();
            if(i < n){
                if(st.empty()) 
                    nge[i] = -1;
                else 
                    nge[i] = st.top();
            }            
            st.push(nums[j]);
        }
        return nge;
    }
};
