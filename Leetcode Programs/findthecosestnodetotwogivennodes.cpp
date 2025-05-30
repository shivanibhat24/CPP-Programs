class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> visited(n,-1), visited_2(n,-1);
        int depth = 0;
        while(node1 != -1 && visited[node1] == -1){
            visited[node1] = depth;
            node1 = edges[node1]; 
            depth++;
        }
        int ans = INT_MAX, idx = -1;
        depth = 0;
        while(node2 != -1 && visited_2[node2] == -1){
            visited_2[node2] = depth;
            if(visited[node2] != -1){
                if(max(visited[node2], depth) < ans){
                    ans = max(visited[node2], depth);
                    idx = node2;
                }else if(max(visited[node2], depth) == ans){
                    if(idx > node2) idx = node2;
                }
            }
            node2 = edges[node2];
            depth++;
        }
        return idx;
    }
};
