class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        arr.push_back({nums2[i], i});
        sort(arr.begin(), arr.end());
        vector<int> res(n);
        int low = 0, high = n - 1;
        for (int x : nums1) 
        {
            if (x > arr[low].first) 
            {
                res[arr[low].second] = x;
                low++;
            } 
            else 
            {
                res[arr[high].second] = x;
                high--;
            }
        }
    return res;
    }
};
