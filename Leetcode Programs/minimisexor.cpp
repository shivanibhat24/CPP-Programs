class Solution {
public:
    int minimizeXor(int num1, int num2) {
        uint8_t bit_set1 = __builtin_popcount(num1);
        uint8_t bit_set2 = __builtin_popcount(num2);
        if (bit_set1 == bit_set2) return num1;
        uint8_t pos = 0;
        while (bit_set1 > bit_set2) {
            uint8_t next_set_bit_pos = __builtin_ctz(num1);
            num1 &= ~(1 << next_set_bit_pos);
            bit_set1--;
            pos = next_set_bit_pos;
        }
        while (bit_set1 < bit_set2) {
            uint8_t next_unset_bit_pos = __builtin_ctz(~num1);
            num1 |= (1 << next_unset_bit_pos);
            bit_set1++;
            pos = next_unset_bit_pos;
        }
        return num1;
    }
};
