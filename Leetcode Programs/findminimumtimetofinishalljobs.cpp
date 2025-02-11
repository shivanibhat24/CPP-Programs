class Solution {
public:
    void backtracking(vector<int>& jobs, int num, int& ans, int k, vector<int>& count){
        if(num == jobs.size()){
            int maxi = *max_element(count.begin(), count.end());
            ans = min(ans, maxi);
            return;
        }
        if(*max_element(count.begin(), count.end()) >= ans) return;
        for(int i = 0 ; i < k ; i++){
            count[i] += jobs[num];
            backtracking(jobs, num+1, ans, k, count);
            count[i] -= jobs[num];
            if(count[i] == 0) break;
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(), jobs.end(), greater<int>());
        int ans = INT_MAX;
        vector<int> count(k);
        backtracking(jobs, 0, ans, k, count);
        return ans;
    }
};
