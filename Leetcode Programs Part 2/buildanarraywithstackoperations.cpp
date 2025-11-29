class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        vector<string> ans;
        vector<int>hash(n+1,0);
        int maxi=target[target.size()-1];
        for(int i=0;i<target.size();i++)
        {
            hash[target[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(i>maxi) break;
            if(hash[i]==1)
            {
                ans.push_back("Push");
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            
        }
        return ans;
    }
};
