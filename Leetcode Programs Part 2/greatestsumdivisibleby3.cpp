class Solution {
public:
    static int maxSumDivThree(vector<int>& nums) {
        const int inf=1e9;
        int sum=0;
        int a[2][2]={{inf, inf}, {inf , inf}};

        for (int x : nums) {
            sum+=x;
            int m=x%3;
            if (m) {
                m--;
                if (x<a[m][0]) a[m][1]=exchange(a[m][0], x);
                else if (x<a[m][1]) a[m][1]=x;
            } 
        }

        int r=sum%3, remove=0;
        if (r) {
            r--;
            remove=min(a[r][0], a[r^1][0]+a[r^1][1]);
            (remove<inf)?sum-=remove:sum=0;
        } 
        return sum;
    }
};
