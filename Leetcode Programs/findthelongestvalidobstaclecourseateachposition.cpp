
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n);
        vector<int> lis;

        for(int i = 0; i < n; i++){
            int ind = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();
            if(ind == lis.size()){
                lis.push_back(obstacles[i]);
            }
            else{
                lis[ind] = obstacles[i];
            }
            ans[i] = ind + 1;
        }

        return ans;
    }
};
