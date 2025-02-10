class Solution {
public:
    int arr[100];    
    int mostBooked(int rooms, vector<vector<int>>& meetings) {
        vector<pair<int,int>> v;
        int n=meetings.size();
        for(int i=0;i<n;i++) {
            v.push_back(make_pair(meetings[i][0],meetings[i][1]));
        }
        sort(v.begin(),v.end());
        memset(arr, 0, sizeof(arr));
        priority_queue<int,vector<int>,greater<int>> freeRooms;
        auto cmpr = [](const pair<long long int, int> &x, const pair<long long int, int> &y) {
            if(x.first==y.first)
                return x.second>y.second;
            return x.first>y.first;
        };
        priority_queue<pair<long long int,int>, vector<pair<long long int,int>>, decltype(cmpr)> pq;

        for(int i=0;i<rooms;i++) {
            freeRooms.push(i);
        }
        for(int i=0;i<n;i++) {
            long long int st=v[i].first,end=v[i].second;
            while(!pq.empty() && pq.top().first<=st) {
                int room = pq.top().second;
                freeRooms.push(room);
                pq.pop();
            }
            if(freeRooms.empty()) {
                pair<long long int,int> earliestEnding = pq.top();
                arr[earliestEnding.second]++;
                pq.pop();
                pq.push({earliestEnding.first + end - st, earliestEnding.second});
            } else {
                int room = freeRooms.top();freeRooms.pop();
                arr[room]++;
                pq.push({end,room});
            }
        }
        int mx=arr[0],val=0;
        for(int i=1;i<rooms;i++) {
            if(arr[i]>mx) {
                mx=arr[i];
                val=i;
            }
        }

        return val;
    }
};
