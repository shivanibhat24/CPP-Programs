class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res=0;
        for(int j=0;j<accounts.size();j++)
        {
            int sum=0;
            for(int k=0;k<accounts[j].size();k++)
            {
                sum=sum+accounts[j][k];
            }
            res=max(res,sum);
        }
        return res;
    }
};
