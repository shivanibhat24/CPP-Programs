class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mpp;
        int n = arr.size();        
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        int ans =-1;
        for( auto &p :mpp){
            if(p.first==p.second){
                ans = max(ans,p.first);
            }
        }
        return ans;
    }
};
