class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        return (find(bits.rbegin()+1, bits.rend(), 0)-bits.rbegin())&1;
    }
};
