class Solution {
public:
    inline static unsigned bb[100][4] = {0};
    inline static unsigned cc[100][4] = {0};

    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        for (int i= 0; i < n; ++i) {
            bb[i][0] = bb[i][1] = bb[i][2] = bb[i][3] = 0;
            cc[i][0] = cc[i][1] = cc[i][2] = cc[i][3] = 0;
            for (int j = i + 1; j < n; ++j){
                if (abs(arr[i] - arr[j]) <= b)
                    bb[i][j/32] |= (1u << (j&31));
                if (abs(arr[i] - arr[j]) <= c)
                    cc[i][j/32] |= (1u << (j&31));
            }
        }
        
        int count = 0;
        unsigned t[4];
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                if (abs(arr[i] - arr[j]) <= a){
                    t[0] = bb[j][0] & cc[i][0];
                    t[1] = bb[j][1] & cc[i][1];
                    t[2] = bb[j][2] & cc[i][2];
                    t[3] = bb[j][3] & cc[i][3];
                    count += __builtin_popcount(t[0]) + 
                            __builtin_popcount(t[1]) + 
                            __builtin_popcount(t[2]) + 
                            __builtin_popcount(t[3]);
                }
            }
        }
        return count;
    }
};
