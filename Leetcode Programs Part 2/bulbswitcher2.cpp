class Solution {
public:
    int flipLights(int n, int presses) {
        if(!presses) return 1;
        if(n == 1) return 2;
        if(n == 2 && presses == 1) return 3;
        if(n == 2 || presses == 1) return 4;
        return presses == 2 ? 7 : 8;
    }
};
