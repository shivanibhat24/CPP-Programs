class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        vector<pair<int,int>> vec;
        for(int i=0;i<intervals.size();i++)
        {
            int fir=intervals[i][0],sec=intervals[i][1];
            vec.push_back({sec,fir});
        }
        sort(vec.begin(),vec.end());
        int ans=0,lst=0,lst2=0;

        for(int i=0;i<vec.size();i++)
        {
            int ok=0;
            if(lst==0 && lst2==0)
            {
                ans+=2;
                lst=vec[i].first;
                lst2=vec[i].first-1;
             //   cout<<lst<<" "<<lst2<<endl;
            }
            else
            {
                if(lst<vec[i].second || lst>vec[i].first)
                {
                    ans++;
                   // cout<<lst<<endl;
                   if(lst2==vec[i].first)
                   lst=vec[i].first-1;
                   else
                    lst=vec[i].first;
                    ok++;
                }
                if(lst2<vec[i].second || lst2>vec[i].first)
                {
                   // cout<<lst2<<endl;
                    ans++;
                    if(ok==0)
                    lst2=vec[i].first;
                    else
                    lst2=vec[i].first-1;
                }
            }
        }
        return ans;
    }
};
