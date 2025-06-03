class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int cnt=0;
        queue<int> q;
        for(auto it:initialBoxes){ q.push(it); }
        while(!q.empty()){
            int sz=q.size();
            vector<int> curr; vector<int> inserted;
            while(sz--){
                int box=q.front(); q.pop();
                curr.push_back(box);
                if(status[box]){
                    cnt+=candies[box]; 
                    for(auto key:keys[box]){status[key]=1;}
                    for(auto other:containedBoxes[box]){q.push(other);}
                }
                else{
                    q.push(box);
                    inserted.push_back(box);
                }
            }
            if(curr==inserted){
                break;
            }
        }
        return cnt;
    }
};
