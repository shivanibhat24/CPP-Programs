class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        double pi = std::acos(-1);
        std::vector<double> angles;
        angles.reserve(points.size()*2);
        int num_points_at_loc = 0;
        for(const auto& p : points){
            int x = p[0]-location[0];
            int y = p[1]-location[1];
            if(x == 0 and y == 0){
                ++num_points_at_loc;
            } else {
                angles.push_back(std::atan2(y, x));
            }
        }
        std::ranges::sort(angles);
        int size = angles.size();
        for(int i=0; i<size; ++i){
            angles.push_back(angles[i]+2*pi);
        }        
        double angle_rad = (angle/180.0)*pi;
        int i = 0;
        int result = 0;
        for(int j=0; j<angles.size(); ++j){
            while(i<=j and std::abs(angles[j]-angles[i])>angle_rad){
                ++i;
            }
            result = std::max(result, j-i+1);
        }
        return result + num_points_at_loc;
    }
};
