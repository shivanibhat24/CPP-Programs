class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int,int>>mp;
        int n = intervals.size();
        for(int i=0;i<n;i++){
            mp.push_back({intervals[i][0],i});
        }
        sort(mp.begin(),mp.end());
        vector<int>res(n);
        for(int i =0;i<n;i++){
            auto it = lower_bound(mp.begin(),mp.end(),make_pair(intervals[i][1],0));
            if(it == mp.end()){
                res[i] = -1;
            }else{
                res[i] = it->second;
            }
        }
        return res;
    }
};
