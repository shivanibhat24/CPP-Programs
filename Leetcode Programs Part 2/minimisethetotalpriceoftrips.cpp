int dp[52][52][2];
class Solution {
public:
    bool dfs(int curr, int prev, int target, vector<vector<int>>&graph, vector<int>&countOccurrences){
        if(curr==target){
            return true;
        }

        for(auto &next: graph[curr]){
            if(next!=prev){
                if(dfs(next, curr, target, graph, countOccurrences)){
                    countOccurrences[next]++;
                    return true;
                }
            }
        }

        return false;
    }

    int dfs_tree_dp(int curr, int prev, bool prevHalve, vector<vector<int>>&graph, vector<int>& price, vector<int>&countOccurrences){
        if(dp[curr][prev][prevHalve]!=-1){
            return dp[curr][prev][prevHalve];
        }

        int val1=price[curr]*countOccurrences[curr];
        int val2=(prevHalve==false?(price[curr]/2)*countOccurrences[curr]:INT_MAX);
        int val3=0;
        for(auto &next: graph[curr]){
            if(next!=prev){
                val1+=dfs_tree_dp(next, curr, false, graph, price, countOccurrences);
                
                if(!prevHalve){
                    val3+=dfs_tree_dp(next, curr, true, graph, price, countOccurrences);
                }
            }
        }

        return dp[curr][prev][prevHalve]=min(val1, val2+val3);
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>>graph(n);
        vector<int>countOccurrences(n, 0);
        for(auto &edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for(auto &trip: trips){
            countOccurrences[trip[0]]++;
            dfs(trip[0], -1, trip[1], graph, countOccurrences);
        }
        memset(dp, -1, sizeof(dp));
        return dfs_tree_dp(0, n, false, graph, price, countOccurrences);
    }
};
