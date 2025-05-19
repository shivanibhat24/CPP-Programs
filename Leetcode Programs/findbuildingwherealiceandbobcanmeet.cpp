class Solution {
public:
    vector<int> ST;
    vector<int> arr;
    int leaves;
    void buildTree() {
        int n = arr.size();
        leaves = pow(2, ceil(log2(n))); 
        ST.assign(2 * leaves - 1, 0);
        for (int i = 0; i < n; i++) {
            ST[i + leaves - 1] = arr[i];
        }
        for (int i = leaves - 2; i >= 0; i--) { 
            ST[i] = max(ST[2 * i + 1], ST[2 * i + 2]);
        }
    }
    int NGE(int i, int x) {
        i = i + leaves - 1;
        int p = (i - 1) / 2;
        while (p >= 0) {
            if (i % 2 == 1 && ST[2 * p + 2] > x) {  
                i = 2 * p + 2;
                while (i < leaves - 1) {  
                    if (ST[2 * i + 1] > x) {
                        i = 2 * i + 1;
                    } else {
                        i = 2 * i + 2;
                    }
                }
                return i - (leaves - 1);
            }
            i = p;
            if (p == 0) break;  
            p = (p - 1) / 2;
        }
        return -1;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        arr = heights;
        buildTree();
        int n = arr.size();
        vector<int> ans;
        for (auto& q : queries) {
            if (q[0] > q[1]) swap(q[0], q[1]);
            if(q[0]==q[1]){
                ans.push_back(q[0]);
                continue;
            }
            if (arr[q[0]] < arr[q[1]]) {  
                ans.push_back(q[1]);  
                continue;
            }
            int i = q[1];
            int x = arr[q[0]];
            int res = NGE(i, x);
            ans.push_back(res);
        }
        return ans;
    }
};
