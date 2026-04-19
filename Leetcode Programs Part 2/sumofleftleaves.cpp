class Solution {
public:
int check(TreeNode* root,bool lefty)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->right==NULL&&root->left==NULL&&lefty==true)
    {
        return root->val;
    }
    int r=0;
    if(root->right!=NULL)
    {
        r= check(root->right,false);
    }
    int l=0;
    if(root->left!=NULL)
    {
        l= check(root->left,true);
    }
    return l+r;
}
    int sumOfLeftLeaves(TreeNode* root) {
        return check(root,false);
    }
};
