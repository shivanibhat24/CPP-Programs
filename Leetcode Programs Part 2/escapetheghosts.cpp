class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int time_to_escape = abs(target[0]) + abs(target[1]);
        bool flag = false;
        int time_for_ghosts = 0;
        for(int i = 0; i < ghosts.size(); i++){
            time_for_ghosts = abs(ghosts[i][0] - target[0]) + abs(ghosts[i][1] - target[1]);
            if(time_to_escape < time_for_ghosts){
                flag = true;
            }
            else{
                flag = false;
                break;
            }
        }
        return flag;
    }
};
