class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottle_drunk=numBottles;
        int empty=numBottles;
        while(empty>=numExchange){
            bottle_drunk+=1;
            empty++;
            empty-=numExchange;
            numExchange++;
        }
return bottle_drunk;
    }
};
