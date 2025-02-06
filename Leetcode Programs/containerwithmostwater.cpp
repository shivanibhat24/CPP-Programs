class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int left = 0;
        int right = height.size() - 1;

        while(left < right) {
            int weight = right - left;
            result = max(result, weight * min(height[left], height[right]));
            if(height[left] < height[right])  {
                left++;
            }
            else {
                right--;
            }
        }
        return result;

    }
};
