class Solution {
public:
    static int minNumberOperations(vector<int>& target) {
        adjacent_difference(target.begin(), target.end(), target.begin());
        return accumulate(target.begin(), target.end(), 0,
        [](int sum, int x){ return sum+=max(0,x);});
    }
};
