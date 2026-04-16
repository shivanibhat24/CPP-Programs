class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int c = 0 ;
        for(int x : jewels){
            for(int y : stones ){
                if(x == y ) c++;
            }
        }
        return c ;
    }
};
