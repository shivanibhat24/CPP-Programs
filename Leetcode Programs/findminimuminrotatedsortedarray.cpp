class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int st = 0, end = n - 1;
        int ans = INT_MAX;        
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (arr[st] <= arr[end]) {
                ans = min(ans, arr[st]);
                break;
            }
            if (arr[mid] >= arr[st]) {
                ans = min(ans, arr[st]);
                st = mid + 1;
            }   
            else if (arr[mid] <= arr[end]) {
                ans = min(ans, arr[mid]);
                end = mid - 1;
            }       
        }        
        return ans;
    }
};
