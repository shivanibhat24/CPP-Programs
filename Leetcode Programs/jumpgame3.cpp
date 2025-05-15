class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        int n = arr.size();
        vector<int> visited(n,-1);
        while (!q.empty()) {
            int index = q.front();
            q.pop();
            if (arr[index] == 0) return true;
            int left = index - arr[index];
            int right = index + arr[index];
            if (left >= 0 && visited[left]!=1) {
                q.push(left);
                visited[left] = 1;  
            }
            if (right < arr.size() && visited[right]!=1) {
                q.push(right);
                visited[right] = 1;  
            }
        }
        return false;
    }
};
