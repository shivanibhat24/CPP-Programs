class Solution {
public:
    vector<vector<int>> answer;
    void dfs(vector<int>& candidates, int target, int index, vector<int>& result){
        if (target < 0){
            return;
        }
        else if (target == 0){
            answer.push_back(result); 
        }
        else {
            for (int i = index ; i < candidates.size() && target >= candidates[i]; ++i){
                if (i > index && candidates[i] == candidates[i - 1]) continue;
                result.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i + 1, result);
                result.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> result;
        dfs(candidates, target, 0, result);
        return answer;
    }
};
