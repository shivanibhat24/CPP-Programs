class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int holdOne = INT_MIN;
        int sellOne = 0;
        int holdTwo = INT_MIN;
        int sellTwo = 0;
        for(int price:prices){
            holdOne = max(holdOne,-price);
            sellOne = max(sellOne,price + holdOne);
            holdTwo = max(holdTwo,-price + sellOne);
            sellTwo = max(sellTwo,price + holdTwo);
        }
        return sellTwo;
    }
};
