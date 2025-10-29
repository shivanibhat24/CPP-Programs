typedef long long ll;
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int X[4] = {0, 0, 1, -1}, Y[4] = {1, -1, 0, 0}, R = grid.size(),
            C = grid[0].size();

        if( grid[1][0] > 1 && grid[0][1] > 1 )
            return -1;

        auto cmp = [&](pair<ll,ll>& p1,pair<ll,ll>& p2){
            return p1.second > p2.second;
        };
        // { idx, time } 
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,decltype(cmp)> pq(cmp);
        pq.push( { 0 , 0 } );
        vector<bool> seen( R * C , false );
        seen[0] = true;
        while( !pq.empty() ){
            auto [ idx , time ] = pq.top();pq.pop();
            int x = idx / C , y = idx % C;
            if( idx == R * C - 1)
                return time;
            
            for(int i=0;i<4;i++){
                int nx = x + X[i], ny = y + Y[i];
                if( nx < 0 || nx >= R || ny < 0 || ny >= C ||
                  seen[nx * C + ny] )
                    continue;
                ll next_grid = grid[nx][ny]; 
                // ll n_time = abs(time - next_grid) % 2LL ? time + (ll)abs(time - next_grid) : time + (ll)abs(time - next_grid)+1LL;
                long long n_time = max(time + 1, (long long)grid[nx][ny]);
                if ((n_time - time) % 2 == 0) {
                    n_time++;
                }
                pq.push( { nx * C + ny , n_time } );
                seen[ nx * C + ny ] = true;
            }
        }
        return -1;
    }
};
