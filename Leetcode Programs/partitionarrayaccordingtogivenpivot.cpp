class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less=0;
        int same=0;
        for(auto x:nums){
            if(x==pivot) same++;
            else if(x<pivot) less++;
        }
        int first=0;
        int second=same+less;
        vector<int> answer(nums.size());
        for(auto x:nums){
            if(x<pivot) answer[first++]=x;
            else if(x==pivot) answer[less++]=x;
            else answer[second++]=x;
        }
        return answer;
    }
};
