class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> ansv;
        for(int i=0;i<20;i++){
            long long int ans1 = pow(x,i);
            if(ans1 >= bound) break;
            for(int j=0;j<20;j++){
                long long int ans2 = ans1 + pow(y,j);
                if(ans2 > bound)
                    break;
                else
                    ansv.insert(ans2);
            }
        }
        vector<int> v (ansv.begin(),ansv.end());
        return v;
    }
};
