class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;
        int min_element = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i] % 2 == 1){
                nums[i] *= 2;
            }
            min_element = min(min_element, nums[i]);
        }
        for(int i=0;i<n;i++){
            if(nums[i] != min_element) pq.push(nums[i]); 
        }
        if(pq.empty()) return 0;
        int ans = pq.top() - min_element;
        int max_element = -1;
        cout<<min_element<<endl;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            if(x < max_element) break;
            ans = min(ans, abs(x - min_element));
            if(x % 2 == 0){
                x = x/2;
                if(x < min_element){
                    pq.push(min_element);
                    min_element = x;
                }
                else pq.push(x);
            }
            else{
                max_element = max(max_element, x);
            }
        }        
        return ans;
    }
};
