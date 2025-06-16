class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        int ans=2*n;
        unordered_map<int,int> m;
        for(auto& x:res){
            if(x[1]>1 && x[1]<10) m[x[0]] |= 1<<(x[1]-2);
        }
        for(auto [row,seats]: m){
            int left = seats & 0b00001111;
            int mid = seats & 0b00111100;
            int right = seats & 0b11110000;
            ans-= left && mid && right ? 2 : 1 ;
        }
        return ans;
    }
};
