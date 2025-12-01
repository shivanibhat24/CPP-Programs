class Solution {
public:
    void findPath(TreeNode* node , vector<string>& ans , string temp){
        temp += to_string(node -> val);
        if(node -> left) findPath(node->left , ans , temp +"->");
        if(node -> right) findPath(node -> right , ans , temp + "->");
        if(!node -> left && !node -> right) ans.push_back(temp); 
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root) findPath(root , ans , "");
        return ans;
    }
};
