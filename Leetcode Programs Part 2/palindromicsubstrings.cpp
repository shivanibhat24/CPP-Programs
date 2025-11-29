class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int center = 0; center < s.size(); center++){
            int max_radius = min(center, (int)(s.size() - 1 - center ));
            int radius = 0;
            while(radius <= max_radius && s[center+radius] == s[center-radius]){
                ++count;
                ++radius;  
            }
            if(center < s.size() - 1 && s[center] == s[center+1]){
                max_radius = min(center, (int)(s.size() - 2 - center ));
                int radius = 0;
                while(radius <= max_radius && s[center+1+radius] == s[center-radius]){
                    ++count;
                    ++radius;  
                }
            }
        }
        return count;
    }
};
