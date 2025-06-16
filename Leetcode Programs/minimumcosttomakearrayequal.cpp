class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int min_num=ranges::min(nums);
        int max_num=ranges::max(nums);
        int nums_size=nums.size();
        long long cost_sum=accumulate(cost.begin(), cost.end(), 0LL);
        long long total=0;
        long long total_weighting;
        int target;
        int next_target;
        long long total_cost1,total_cost2;
        long long min_cost=LLONG_MAX;
        if (min_num==max_num) return 0;
        for (int j=0;j<nums_size;j++)
        {
            total=total+(long long)nums[j]*cost[j];
        }
        total_weighting=total/cost_sum;
        #if 1
        #else
        if ((total-total_weighting*cost_sum)>((total_weighting+1)*(long long)cost_sum-total))
        {
            total_weighting++;
        }
        #endif
        total_cost1=0;
        total_cost2=0;
        target=total_weighting;
        for (int j=0;j<nums_size;j++)
        {
            total_cost1=total_cost1+abs(nums[j]-target)*(long long)cost[j];
            total_cost2=total_cost2+abs(nums[j]-target-1)*(long long)cost[j];
        }        
        while (1)
        {
            if (total_cost1<total_cost2)
            {
                if (total_cost1<min_cost) min_cost=total_cost1;
                next_target=(target+min_num)/2;
                if (next_target==target) return min_cost;
                max_num=target;
            }
            else if (total_cost1>total_cost2)
            {
                if (total_cost2<min_cost) min_cost=total_cost2;
                next_target=(target+1+max_num)/2;
                
                if (next_target==max_num) return min_cost;
                min_num=target+1;
            }
            else
            {
                return total_cost1;
            }
            target=next_target;
            total_cost1=0;
            total_cost2=0;
            for (int j=0;j<nums_size;j++)
            {
                total_cost1=total_cost1+abs(nums[j]-target)*(long long)cost[j];
                total_cost2=total_cost2+abs(nums[j]-target-1)*(long long)cost[j];
            }
        }        
        return min_cost;
    }
};
