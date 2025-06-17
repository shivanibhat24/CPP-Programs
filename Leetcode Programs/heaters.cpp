class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());        
        int i=0,rad =0;
        for(int h : houses){
            while(i < heaters.size()-1 && abs(heaters[i+1]-h) <= abs(heaters[i]- h)){
                i++;
            }
            rad = max(rad, abs(heaters[i]-h));
        }
        return rad;
    }
};
