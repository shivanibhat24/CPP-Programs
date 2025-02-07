#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // GNU Policy-Based Data Structure

using namespace std;
using namespace __gnu_pbds;

static auto init = []() {   
    ios::sync_with_stdio(false);   
    cin.tie(nullptr);   
    return nullptr; 
}();

class Solution { 
public:   
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {     
        gp_hash_table<int, int> ball_to_color;
        gp_hash_table<int, int> color_counts;
        int num_colors = 0;     
        vector<int> result;
        result.reserve(queries.size());
        for (const auto& query : queries) {       
            int ball = query[0], color = query[1];
            auto it = ball_to_color.find(ball);
            if (it != ball_to_color.end()) {  
                int prev_color = it->second;
                if (prev_color == color) {  
                    result.push_back(num_colors);
                    continue;
                }
                if (--color_counts[prev_color] == 0) { 
                    color_counts.erase(prev_color);
                    --num_colors;
                }
            }
            ball_to_color[ball] = color;
            if (++color_counts[color] == 1) ++num_colors;

            result.push_back(num_colors);
        }     

        return result;
    } 
};
