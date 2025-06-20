class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node = new TreeNode(val);
            node->left = root ;
            return node;
        }
        queue<TreeNode*>q;
        q.push(root);
        int currLevel = 1;
        while(!q.empty()){
            int size = q.size() ;
            for(int i=0 ; i<size ;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(currLevel == depth-1){
                   TreeNode* temp1 = curr->left;
                   TreeNode* temp2 = curr->right;
                    curr->left = new TreeNode(val) ;
                    curr->right = new TreeNode(val);
                    curr->left->left = temp1;
                    curr->right->right = temp2;
                    if(curr->left->left){
                        
                        q.push(curr->left->left);
                        
                    }
                    if(curr->right->right){
                        q.push(curr->right->right);
                        
                    }                                       
                }
                else{
                    if(curr->left){
                        q.push(curr->left);
                    }
                    if(curr->right){
                        q.push(curr->right);
                    }

                }                
            }
            currLevel++;
        }
        return root;
    }
};
