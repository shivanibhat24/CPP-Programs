class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;  
        int dx = 0, dy = 1;  
        
        for (char instruction : instructions) {
            if (instruction == 'G') {
                x += dx;
                y += dy;
            } else if (instruction == 'L') {
                int temp = dx;
                dx = -dy;
                dy = temp;
            } else if (instruction == 'R') {
                int temp = dx;
                dx = dy;
                dy = -temp;
            }
        }
        if(x == 0 && y == 0 || dx != 0 || dy != 1){
            return true;
        }
        else{
            return false;
        }
    }
};
