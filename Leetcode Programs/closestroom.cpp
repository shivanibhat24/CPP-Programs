#include <vector>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int q_n = queries.size();
        vector<tuple<int, int, int>> q_list;
        for (int i = 0; i < q_n; i++) {
            q_list.push_back({queries[i][0], queries[i][1], i});
        }
        sort(q_list.begin(), q_list.end(), [](const auto& a, const auto& b) {
            return get<1>(a) > get<1>(b);
        });
        sort(rooms.begin(), rooms.end(), [](const auto& a, const auto& b) {
            return a[1] > b[1];
        });        
        int r_idx = 0;
        int r_n = rooms.size();
        multiset<int> room_ids; 
        vector<int> result(q_n, -1);        
        for (auto& [preferred_r_idx, min_sz, q_idx] : q_list) {
            while (r_idx < r_n && rooms[r_idx][1] >= min_sz) {
                room_ids.insert(rooms[r_idx][0]);
                r_idx++;
            }            
            if (room_ids.empty()) {
                continue; 
            }
            auto it = room_ids.lower_bound(preferred_r_idx);            
            int best_room = -1;
            int min_diff = INT_MAX;
            if (it != room_ids.end()) {
                int room_id = *it;
                int diff = abs(room_id - preferred_r_idx);
                if (diff < min_diff || (diff == min_diff && room_id < best_room)) {
                    min_diff = diff;
                    best_room = room_id;
                }
            }
            if (it != room_ids.begin()) {
                --it;
                int room_id = *it;
                int diff = abs(room_id - preferred_r_idx);
                if (diff < min_diff || (diff == min_diff && room_id < best_room)) {
                    min_diff = diff;
                    best_room = room_id;
                }
            }            
            result[q_idx] = best_room;
        }        
        return result;
    }
};
