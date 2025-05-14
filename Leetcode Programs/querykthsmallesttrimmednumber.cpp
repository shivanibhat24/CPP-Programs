class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        const int len = nums[0].length();
        std::vector<std::pair<std::string, int>> v;
        const int n = nums.size();
        v.reserve(n);        
        for (int i = 0; i < n; ++i)
        {
            v.push_back(std::make_pair(nums[i], i));
        }        
        std::vector<int> result;
        result.resize(queries.size());        
        std::vector<std::pair<std::string, int>> aux(n);        
        for (int index = len; --index >= 0;)
        {
            int counters[10]{};            
            for (const std::pair<std::string, int>& num : v)
            {
                ++counters[num.first[index] - '0'];
            }            
            for (int i = 1; i < 10; ++i)
            {
                counters[i] += counters[i - 1];
            }            
            for (int i = n; --i >= 0;)
            {
                aux[--counters[v[i].first[index] - '0']] = v[i];
            }            
            std::swap(v, aux);            
            for (int i = 0; i < queries.size(); ++i)
            {
                const std::vector<int>& q = queries[i];                
                if (q[1] + index == len)
                {
                    result[i] = v[q[0] - 1].second;
                }
            }
        }        
        return result;
    }
};
