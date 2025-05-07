class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> start(2, 0);
        for(char ch : moves){
            if(ch == 'L'){
                --start[1];
            }else if(ch == 'R'){
                ++start[1];
            }else if(ch == 'U'){
                --start[0];
            }else{
                ++start[0];
            }
        }        
        return start[0] == start[1] && start[0] == 0;
    }
};
