class Solution {
public:
    static bool comp(pair<int,int> &a,pair<int,int> &b){
        return a.first<b.first;
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        vector<pair<int,int>> nums;
        for(int i=0;i<n;i++){
            nums.push_back({courses[i][1],courses[i][0]});
        }
        sort(nums.begin(),nums.end(),comp);
        priority_queue<int> q;
        int ans=0;
        int end=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i].second>nums[i].first){
                continue;
            }
            if((end+nums[i].second)<=nums[i].first){
                q.push(nums[i].second);
                end+=nums[i].second;
                ans++;
            }
            else{
                int maxlen=q.top();
                int newend=end-maxlen;
                if(maxlen>nums[i].second && (newend+nums[i].second)<=nums[i].first){
                    q.pop();
                    end-=maxlen;
                    end+=nums[i].second;
                    q.push(nums[i].second);
                }
            }
        }
        return ans;
    }
};
