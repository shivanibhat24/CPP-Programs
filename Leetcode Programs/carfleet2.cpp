class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n=cars.size();
        stack<int>st;
        vector<double>ans(n,-1);
        for(int i=n-1;i>=0;i--){
                int p1=cars[i][0],s1=cars[i][1];
            while(!st.empty()){
                auto top=st.top();
                int p2=cars[top][0],s2=cars[top][1];
                if(s1<=s2){
                    st.pop();
                    continue;
                }
                double t=(double)(p2-p1)/(double)(s1-s2);
                if(ans[top]>0 && t>ans[top])st.pop();
                else {
                    ans[i]=t;
                    break;
                }
            }
            st.push(i);
        }
        return ans;
    }
};
