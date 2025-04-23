class Solution {
public:
   bool xorGame(vector<int>& nums) {
    int XOR= 0;
    for (int i = 0; i < nums.size(); i++)XOR = (XOR ^nums[i]);
    if (XOR == 0)return true;
    return !(nums.size() % 2);
}
};
