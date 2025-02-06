class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>at(n+1);
        int maxi=0;
        at[0]=0;
        for(int i=1;i<=n;i++){
            at[i]=at[i-1]+gain[i-1];
        }
        sort(at.begin(),at.end());
        maxi=at[n];
        return maxi;
    }
};
