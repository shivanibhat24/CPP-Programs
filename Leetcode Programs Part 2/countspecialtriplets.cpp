class Solution {
public:
    int specialTriplets(vector<int>& numbers) {
        int counts[100001][2];
        memset(&counts, 0, sizeof(counts));
        int size_n = numbers.size(), result = 0;
        for (int index = 0; index < size_n; ++index) {
            int& number = numbers[index];
            if ((number & 1) == 0) {
                result = (result + counts[number >> 1][1]) % 1000000007;
            }
            if (number <= 50000) {
                counts[number][1] = (counts[number][1] + counts[number << 1][0]) % 1000000007;
            }
            ++counts[number][0];
        }
        return result;
    }
};
