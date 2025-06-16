class Solution {
public:
    int getnextidx(vector<int>& nums,int p , int cur_dir)
    {
        int n=nums.size();
        int next_idx=((p + nums[p]) % n + n) % n;
        int next_dir=1;
        if(nums[next_idx]<0)
        {
            next_dir=-1;
        }
        if(cur_dir!=next_dir || p==next_idx)
        {
            return -1;
        }
        return next_idx;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==1) continue;
            int sp=i,fp=i;
            int cur_dir=1;
            if(nums[i]<0)
            {
                cur_dir=-1;
            }
            while(1)
            {
                sp=getnextidx(nums,sp,cur_dir);
                fp=getnextidx(nums,fp,cur_dir);                
                if(sp==-1 || fp==-1)
                {
                    break;
                }
                vis[sp]=1;
                vis[fp]=1;
                fp=getnextidx(nums,fp,cur_dir);
                if(fp==-1)
                {
                    break;
                }
                if(sp==fp)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
