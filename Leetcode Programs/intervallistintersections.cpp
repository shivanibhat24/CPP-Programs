class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int n = firstList.size();
        int m =  secondList.size();
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            int x = max(firstList[i][0], secondList[j][0]);
             int y = min( firstList[i][1], secondList[j][1]);
             if(y-x >= 0) ans.push_back({x, y});
             if(firstList[i][1] < secondList[j][1]) i++;
             else j++;
        }
        return ans;
    }
};
