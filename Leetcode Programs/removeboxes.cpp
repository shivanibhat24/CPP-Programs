class Solution {
    int boxes_colors[101];
    int boxes_sizes[101];
    int dp[101][101][101] = {};
public:
    int solve(int start, int end, int k){
        if (end < start)  return 0;
        if (dp[start][end][k] > 0) return dp[start][end][k] ;
        int new_k = k+boxes_sizes[start];
        int max_score = new_k*new_k+
                        solve(start+1, end, 0);
        for(int i=start+1; i <= end; i++){
            if (boxes_colors[i] == boxes_colors[start]){
                int curr_score = solve(i,end,new_k) + solve(start+1,i-1,0);
                max_score = max(max_score,curr_score );
            }
        }
        dp[start][end][k] = max_score;
        return max_score;
    }
    int removeBoxes(vector<int>& arr) {
        int num_boxes = 0;
        int n = size(arr);
        for(int i=0;i<n;i++){
            int start = i;
            while(i<n-1 && arr[i+1] == arr[i]){
                i++;
            }
            boxes_colors[num_boxes] = arr[i];
            boxes_sizes[num_boxes++] =  i-start + 1;
        }
        return solve(0,num_boxes-1,0);
    }
};
