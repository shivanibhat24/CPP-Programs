class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        long long sum1=0,sum2=0;
        bool flag1=false,flag2=false;
        for(auto &n :nums1){
            sum1+=n;
            if(n==0) {
                sum1++;
                flag1=true;
            }
        }
        for(auto &n :nums2){
            sum2+=n;
            if(n==0) {
                sum2++;
                flag2=true;
            }
        }
        if(flag1==false && sum1<sum2 || flag2==false && sum2<sum1){
            return -1;
        } 
        return max(sum1,sum2);

    }
};
