class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        bool e[101] = {0};
        int size = nums.size();

        for (int i = size - 1; i >= 0; --i) {
            if (e[nums[i]])
                return ceil(double(i + 1) / 3);
            e[nums[i]] = true;
        }
        
        return 0;
    }
};
