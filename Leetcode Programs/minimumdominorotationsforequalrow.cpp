class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int mswaps=INT_MAX;
        for(int val=1;val<=6;val++){
            int tSwap=0, bSwap=0;
            for(int i=0;i<tops.size();i++){
                if(tops[i]!=val && bottoms[i]!=val){tSwap=INT_MAX; bSwap=INT_MAX; break;}
                if(tops[i]!=val){tSwap++;}
                if(bottoms[i]!=val){bSwap++;}
            }
            mswaps = min(mswaps, min(tSwap,bSwap));
        }
        return mswaps==INT_MAX?-1:mswaps;
    }
};
