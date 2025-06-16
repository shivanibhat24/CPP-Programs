class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n= votes.size();
        vector<vector<int>> v (26, vector<int> (votes[0].size(),0));
        for(int i=0 ;i<n ; i++)
        {   
            for(int j=0 ; j< votes[0].size();j++)
            {
                int x= votes[i][j]-'A';
                v[x][j]++;
            }
        }
        string res= votes[0];
        sort(res.begin(),res.end() ,[&](char &a, char &b)
        {
             if(v[a-'A']!= v[b-'A'])
             {
                return v[a-'A']> v[b-'A'];
             }
             else
             {
                return a<b;
             }
        });
        return res;
    }
};
