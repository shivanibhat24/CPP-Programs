class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        vector<int> count(10001, 0);
        for (int b : barcodes) 
            ++count[b];
        int maxNum = 0;
        for (int num = 1; num <= 10000; ++num) {
            if (count[num] > count[maxNum])
                maxNum = num;  
        }
        vector<int> ans(n);
        int i = 0;
        auto fill = [&](int num) {
            while (count[num]-- > 0) {
                ans[i] = num;
                i = (i + 2 < n ? i + 2 : 1);
            }
        };
        fill(maxNum);
        for (int num = 1; num <= 10000; ++num) {
            if (num != maxNum && count[num] > 0)
                fill(num);
        }
        return ans;
    }
};
