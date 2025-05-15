class Solution {
public:
    bool sumGame(string num) {
        int sumLeft = 0, sumRight = 0;
        int brackLeft = 0, brackRight = 0;

        for(int i = 0; i < num.size()/2; i++) {
            if(num[i] == '?') {
                brackLeft += 1;
            } else {
                sumLeft += num[i] - '0';
            }
        }

        for(int i = num.size()/2; i < num.size(); i++) {
            if(num[i] == '?') {
                brackRight += 1;
            } else {
                sumRight += num[i] - '0';
            }
        }

        if((brackLeft + brackRight)%2 != 0)
            return true;

        int subSum = sumLeft - sumRight;
        int subBrack = brackRight - brackLeft;


        return subSum != 9*subBrack/2;

    }
};
