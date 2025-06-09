class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int k) {
        int n=w.size();
        vector<pair<double,int>> v(n);
        for(int i=0;i<n;i++){
            v[i]={(double)w[i]/q[i],i};
        }
        sort(v.begin(),v.end());
        priority_queue<int> pq;
        double qs=0;
        double res=1e12;
        for(int i=0;i<n;i++){
            qs+=q[v[i].second];
            pq.push(q[v[i].second]);
            if(pq.size()>k) {qs-=pq.top(); pq.pop();}
            if(pq.size()==k) {res=min(res,qs*v[i].first);}
        }
        return res;
    }
};
