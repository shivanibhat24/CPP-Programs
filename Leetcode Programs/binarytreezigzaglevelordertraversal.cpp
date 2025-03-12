class Solution {
public:
    void levelTravarsal(TreeNode* root, vector<vector<int>>& result){
        queue<TreeNode*> q;
         q.push(root);
        while(!q.empty()){
            vector<int> level;
            int s=q.size();
            for(int i = 0;i<s;i++){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            result.push_back(level);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }

        vector<vector<int>> result;
        levelTravarsal(root, result);
        int m = result.size();
        for(int i = 1; i < m ; i += 2){
            reverse(result[i].begin(),result[i].end());
        }
        return result;
    }
};
