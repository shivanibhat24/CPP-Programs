class Solution {
public:
    class Detail {
    public:
        bool bst;
        int sum;
        int min, max ;
        Detail(int data) {
            bst = true;
            sum = data;
            min = data;
            max = data;
        }
    };
    Detail* solve(TreeNode* root, int & totalsum)
    {
        if(!root->left&&!root->right)
        {
            totalsum = max(totalsum,root->val);
            return new Detail(root->val);
        }
        else if(!root->left)
        {
            Detail* t = solve(root->right,totalsum);
            if(t->bst&&t->min>root->val)
            {
                t->sum=t->sum+root->val;
                t->min=root->val;
                totalsum=max(totalsum,t->sum);
                return t;
            }
            else
            {
                t->bst=false;
                return t;
            }
        }
        else if(!root->right)
        {
            Detail* t = solve(root->left,totalsum);
            if(t->bst&&t->max<root->val)
            {
                t->sum=t->sum+root->val;
                t->max=root->val;
                totalsum=max(totalsum,t->sum);
                return t;
            }
            else
            {
                t->bst=false;
                return t;
            }
        }
        else
        {
            Detail* l = solve(root->left,totalsum);
            Detail* r = solve(root->right,totalsum);
            if(l->bst&&r->bst&&l->max<root->val&&r->min>root->val)
            {
                Detail* res = new Detail(root->val);
                res->min=l->min;
                res->max=r->max;
                res->sum=l->sum+r->sum+root->val;
                totalsum=max(totalsum,res->sum);
                return res;
            }
            else
            {
                l->bst=false;
                return l;
            }
        }
    }    
    int maxSumBST(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};
