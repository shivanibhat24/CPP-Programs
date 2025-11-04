class Solution {
public:
    static constexpr int kMod = 1e9 + 7;
    int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }
        int corners = 4;
        int top_bottom = 2;
        int left_right = 2;
        int zero = 1;
        for (int i = 0; i < n - 1; ++i) {
            auto curr_corners = corners;
            auto curr_left_right = left_right;
            corners = ((top_bottom * 2) % kMod + (left_right * 2) % kMod) % kMod; 
            top_bottom = curr_corners; 
            left_right = ((zero * 2) % kMod + curr_corners) % kMod;  
            zero = curr_left_right; 
        }
        return (((corners + top_bottom) % kMod + left_right) % kMod + zero) % kMod;
    }
};
