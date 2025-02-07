class Solution
{
public:
    int kthFactor(int n, int k)
    {
        for(int curr=1; curr<=n; curr++) {if(n%curr==0) k--; if(!k) return curr;}
        return -1;    
    }
};
