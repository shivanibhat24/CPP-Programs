/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N"; 
        return to_string(root->val) +" "+ serialize(root->left) + " "+serialize(root->right); 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string& data) {
        
        if(data.front()=='N')
        {
            data.erase(0,2);  
            return NULL; 
        }
          string str;
         while(data.front()!=' ')
         {
           str=str+data.front();
            data.erase(0,1);  
         }
        TreeNode* node=new TreeNode(stoi(str));  
         data.erase(0,1);  

        node->left=deserialize(data);
        node->right=deserialize(data);

        return node; 
    }
};
