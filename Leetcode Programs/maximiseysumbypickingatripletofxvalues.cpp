class Solution {
private:
    pair<int, int> getMaxValueOfY(vector<int>& x, vector<int>& y, int x1, int x2){
        int n = x.size();
        int i;
        int maxval = 0;
        int maxx;
        for(i=0;i<n;i++){
            if(x[i] != x1 && x[i] != x2 && y[i] > maxval){
                maxval = y[i];
                maxx = x[i];
            }
        }
        return {maxx, maxval};
    }
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int maxx, maxy;
        int i;
        int n = x.size();
        pair<int, int> val;
        val = getMaxValueOfY(x, y, -1, -1);
        maxx = val.first; maxy = val.second;
        int maxx2, maxy2;
        val = getMaxValueOfY(x, y, maxx, -1);
        maxx2 = val.first;
        maxy2 = val.second;
        int maxx3, maxy3;
        val = getMaxValueOfY(x, y, maxx, maxx2);
        maxx3 = val.first;  maxy3 = val.second;
        if(maxy == 0 || maxy2 == 0 || maxy3 == 0){
            return -1;
        }
        return maxy + maxy2 + maxy3;
    }
};
