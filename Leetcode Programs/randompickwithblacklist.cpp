class Solution {
public:
    int n;
    vector<int> blist;
    Solution(int n, vector<int>& blacklist) {
        sort(blacklist.begin(),blacklist.end());
        this->blist=blacklist;
        for(int i=0;i<(int)blist.size();i+=1)
        {
            blist[i]=blist[i]-i;
        }
        this->n=n-blist.size();
    }    
    int pick() {
        int val=rand()%n;
        int idx=upper_bound(blist.begin(),blist.end(),val)-blist.begin();
        return val+idx;
    }
};
