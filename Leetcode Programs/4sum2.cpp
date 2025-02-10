class Solution {
public:
    #define s(x) sort(x.begin(),x.end())
    int fourSumCount(vector<int>& n1, vector<int>& n2, vector<int>& n3, vector<int>& n4) {
        int n=n1.size();
        int ans=0;
        s(n1);
        s(n2);
        s(n3);
        s(n4);
        unordered_map<int,int> m1,m2;
        for(auto i:n1)
        {
            for(auto j:n2)
            {
                m1[i+j]++;
            }
        }
        for(auto i:n3)
        {
            for(auto j:n4)
            {
                m2[i+j]++;
            }
        }
        for(auto i:m1)
        {
            int val=i.first;
            int freq=i.second;
            if(m2[-val]>0)
            {
                int f=m2[-val];
                ans+=(f*freq);
            }
        }
        return ans;
    }
};
