struct JobSpec
{
    int endTime;
    int startTime;
    int profit;    
};
int findLastJob(int key, int l, int h, std::vector<JobSpec>& jobs)
{
    while(l < h)
    {
        int mid = (l+h+1) / 2;
        if(jobs[mid].endTime > key)
        {
            h = mid-1;
        }
        else
        {
            l = mid;
        }
    }
    return jobs[l].endTime > key ? -1 : l;
}
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        std::vector<JobSpec> jobs;
        for(int i=0; i < startTime.size(); i++)
        {
            jobs.push_back({ endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end(), [](const JobSpec& a, const JobSpec& b){
            return a.endTime < b.endTime;
        });
        std::vector<int> maxProfits(endTime.size(),0);
        maxProfits[0] = jobs[0].profit;
        for(int i=1; i < jobs.size();i++)
        {
            auto endTime = jobs[i].endTime;
            auto startTime = jobs[i].startTime;
           
            auto pos = findLastJob(startTime,0 , i, jobs);
                
            if(pos==-1)
            {            
                maxProfits[i] = std::max(jobs[i].profit, maxProfits[i-1]);
            }
            else
            {
                maxProfits[i] = std::max(maxProfits[pos] +jobs[i].profit, maxProfits[i-1]); 
            }           
        }
        return maxProfits[jobs.size()-1];
    }
};
