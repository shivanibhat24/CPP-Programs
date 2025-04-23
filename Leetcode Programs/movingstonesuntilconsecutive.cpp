class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int>arr={a,b,c};
        sort(begin(arr),end(arr));
        int mini=0;
        int maxi=0;
        if(arr[2]-arr[0]==2){
            return {0,0};
        }
        if(min(arr[1]-arr[0],arr[2]-arr[1])<=2){
            mini=1;
        }
        else{
            mini=2;
        }
        maxi=arr[2]-arr[0]-2;
        return {mini,maxi};
    }
};
