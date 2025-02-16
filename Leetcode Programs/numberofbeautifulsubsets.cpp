class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int x : nums)
            count[x] += 1;
        unordered_map<int, vector<pair<int, int>>> map;
        for(auto [val, freq] : count)
            map[val % k].push_back({val, freq});
        int ans = 1;
        for(auto & [r, arr] : map)
        {
            sort(arr.begin(), arr.end());
            int take, notake;
            take = 0;
            notake = 1;
            for(int i = 0; i < arr.size(); ++i)
            {
                int tempT = take;
                int tempN = notake;
                if(i > 0 && abs(arr[i].first - arr[i - 1].first) == k)
                {
                    take = tempN * ((1<<arr[i].second) - 1);
                    notake = (tempT + tempN) * 1;
                }
                else
                {
                    take = (tempT + tempN) * ((1<<arr[i].second) - 1);
                    notake = (tempT + tempN) * 1;                    
                }
            }
            ans = ans * (take + notake);
        }
        return ans - 1;
    }
};
