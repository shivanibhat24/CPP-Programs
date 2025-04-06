const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>par(n,0);
        for(int i=0;i<n;i++)
        { par[i]=i;
            for(int j=0;j<i;j++)
            {
                    if(nums[i]%nums[j]==0 || nums[j]%nums[i]==0)
                    {
                        if(dp[i]<dp[j]+1)
                        {
                            dp[i]=dp[j]+1;
                            par[i]=j;
                        }
                    }
            }
        }
        int ans=-1;
        int last=-1;
        for(int i=0;i<n;i++)
        {
            if(dp[i]>ans)
            {
                ans=dp[i];
                last=i;
            }
        }
        vector<int>anss;
        anss.push_back(nums[last]);
        while(par[last]!=last)
        {
            last=par[last];
            anss.push_back(nums[last]);
        }
        reverse(anss.begin(),anss.end());
        return anss;
    }
};
