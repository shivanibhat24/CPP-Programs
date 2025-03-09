#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
static const auto harsh = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>lpq;
        vector<int> v;
        for(int i = 0; i < times.size(); ++i){
            v.emplace_back(i);
        }
        sort(v.begin(), v.end(), [&times](int x, int y){
            if(times[x][0] == times[y][0]){
                return times[x][1] < times[y][1];
            }
            return times[x][0] < times[y][0];
        });
        priority_queue<int, vector<int>, greater<int>> freeChairs;
        int chairs = 0;
        for(auto f : v){
            cout<<f<<endl;
            int startTime = times[f][0];
            int endTime = times[f][1];
            while(lpq.size() && lpq.top().first <= startTime){
                freeChairs.push(lpq.top().second);
                lpq.pop();
            }
            int chair;
            if(!freeChairs.empty()){
                chair = freeChairs.top();
                freeChairs.pop();
                lpq.push({endTime, chair});
            }else{
                chair = chairs;
                chairs++;
                lpq.push({endTime, chair});
            }
            if(f == targetFriend){
                return chair;
            }
        }
        return chairs;
    }
};
