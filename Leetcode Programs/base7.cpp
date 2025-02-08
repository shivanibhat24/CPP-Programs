class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool isNegative = num < 0;
        num = abs(num);
        char buffer[12];
        int index = 0;
        while (num) {
            buffer[index++] = '0' + (num % 7);
            num /= 7;
        }
        if (isNegative) buffer[index++] = '-';
        int i = 0, j = index - 1;
        while (i < j) swap(buffer[i++], buffer[j--]);
        return string(buffer, index);
    }
};
