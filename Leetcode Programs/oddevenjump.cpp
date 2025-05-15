class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> next_greater(n,-1), next_smaller(n,-1);
        stack<int>s;
        vector<pair<int,int>>sortedPairs;
        for(int i=0;i<arr.size();i++){
            sortedPairs.push_back({arr[i],i});
        }
        sort(sortedPairs.begin(), sortedPairs.end());
        for(auto [val,i]: sortedPairs){
            while(!s.empty() && s.top()<i){
                next_greater[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        s = stack<int>();
        sort(sortedPairs.begin(), sortedPairs.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first == b.first) return a.second < b.second; 
            return a.first > b.first; 
        });
        for(auto [val,i]: sortedPairs){
            while(!s.empty() && s.top()<i){
                next_smaller[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        vector<bool> oddReachable(n, false), evenReachable(n, false);
        oddReachable[n - 1] = evenReachable[n - 1] = true;  
        int count = 1;
        for(int i=n-2;i>=0;i--){
            if(next_greater[i]!=-1){
                oddReachable[i] = evenReachable[next_greater[i]];
            }
            if(next_smaller[i]!=-1){
                evenReachable[i] = oddReachable[next_smaller[i]];
            }
            if(oddReachable[i]) count++; 
        }
        return count;
    }
};
