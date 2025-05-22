class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int cnt = 0;
        unordered_map<int, int>umap;
        for(int i=0; i<pairs.size(); ++i){
            umap[pairs[i][0]] = pairs[i][1];
            umap[pairs[i][1]] = pairs[i][0];
        }
        for(int i=0; i<n; ++i){
            int paired_with = umap[i];
            bool t = true;
            int j = 0;
            while(preferences[i][j] != paired_with){
                int e = preferences[i][j];
                int e_paired_with = umap[e];
                for(int k=0; k<preferences[0].size(); ++k){
                    if(preferences[e][k]==i){
                        t = false;
                        break;
                    }
                    if(preferences[e][k]==e_paired_with) break;
                }
                if(!t) break;
                ++j;
            }
            if(!t) ++cnt;
        }
        return cnt;
    }
};
