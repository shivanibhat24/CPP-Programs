class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for(int& price : prices) {
            if (maxProfit <  price - minPrice) {
                maxProfit = price - minPrice;
            }

            if (minPrice > price) {
                minPrice = price;
            }
        }

        return maxProfit;
    }
};
