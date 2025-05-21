class Solution {
public:
    int ans = 0;
    void recursion(int level, set<int>& choices){
        if(level == 0){
            ans++;
            return;
        }
        set<int> temp = choices;
        for(auto it : temp){
            if(it%level == 0 || level%it == 0){
                choices.erase(it);
                recursion(level-1,choices);
                choices.insert(it);
            }
        }
        return;
    }
    int countArrangement(int n) {
        ans = 0;
        set<int> choices; 
        for(int i = 1 ; i <= n ; i++){
            choices.insert(i);
        }  
        recursion(n,choices);
        return ans;
    }
};
