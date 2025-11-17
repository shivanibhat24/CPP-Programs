class Solution {
    bool possible(vector<int>& window, int maxC, int target){
        int p = -1;
        for (int i = 0; i < window.size(); i++){
            if (i <= p) continue;
            if (window[i] > target){
                if (--maxC < 0) return false;
                p = i + target;
            }
        }
        return true;
    }
    int minStableWindow(vector<int>& window, int maxC){
        int low = 0, high = window.size();
        while (low < high){
            int mid = (low + high) / 2;
            if (possible(window,maxC,mid))
                high = mid;
            else low = mid + 1;
        }
        return low;
    }
public:
    int minStable(vector<int>& nums, int maxC) {
        int n = nums.size();
        int m = n << 1;
        while (m & (m-1)) m = m & (m-1);
        vector<int> range_gcd(2*m,1);
        for (int i = 0; i < n; i++)
            range_gcd[m+i] = nums[i];
        for (int i = m-1; i > 0; i--)
            range_gcd[i] = gcd(range_gcd[2*i],range_gcd[2*i+1]);
        vector<int> window(n,0);
        for (int i = 0, j = 0; i < n; i++){
            for (j = max(i,j); j < n; j++){
                int l = m + i;
                int r = m + j;
                int val = nums[i];
                while (l < r){
                    if (~r & 1)
                        val = gcd(val,range_gcd[r]);
                    if (~l & 1)
                        val = gcd(val,range_gcd[l+1]);
                    l /= 2; r = (r-1) / 2;
                }
                if (val == 1) break;
            }
            window[i] = j - i;
        }
        return minStableWindow(window,maxC);
    }
};
