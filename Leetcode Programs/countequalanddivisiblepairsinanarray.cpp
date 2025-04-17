class Solution {
public:
    static int countPairs(vector<int>& nums, int k) {
        const int n=nums.size();
        vector<char> freq[101];
        for(int i=0; i<n; i++){
            int x=nums[i];
            freq[x].push_back(i);
        }
        int cnt=0;
        for( auto& fs: freq){
            if (fs.size()<2) continue;
            int fz=fs.size();
            for(int i=0; i<fz-1; i++)
                for(int j=i+1; j<fz; j++)
                    cnt+=(fs[i]*fs[j]%k==0);
        }
        return cnt;
    }
};
