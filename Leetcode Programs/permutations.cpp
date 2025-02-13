class Solution {
public:
     void permutation(vector<int>& nums, int st, int end, vector<vector<int>>& result) {
    if (st == end) {
        result.push_back(nums); 
        return;
    }
    for (int i = st; i <= end; i++) {
        swap(nums[st], nums[i]); 
        permutation(nums, st + 1, end, result);
        swap(nums[st], nums[i]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    permutation(nums, 0, nums.size() - 1, result);
    return result;
}
};
