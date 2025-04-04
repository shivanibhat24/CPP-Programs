class Solution {
public:
    using info=pair<TreeNode*, TreeNode*>;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return root;
        info q[1000];
        TreeNode* x2T[1001];// x -> TreeNode*
        int par[1001]; // x -> parent->val
        int front=0, back=0;
        q[back++]={root, NULL};
        int d=0;
        vector<int> level;// 1D vector is enough
        for( ; front!=back; d++){
            int qz=back-front;
            level.assign(qz, -1);
            for(int i=0; i<qz; i++){
                auto [node, parent]=q[front++];
                int x=node->val;
                int y=(!parent)?-1:parent->val;
                level[i]=x;
                par[x]=y;
                x2T[x]=node;
                if (node->left) q[back++]={node->left, node};
                if (node->right) q[back++]={node->right, node};
            } 
        }
        d--;
        if (level.size()==1) return x2T[level[0]];
        int s=level[0], t=level.back();
        while(s!=t){
        //    cout<<"s="<<s<<" t="<<t<<" par[s]="<<par[s]<<" par[t]="<<par[t]<<endl;
            s=par[s];
            t=par[t];
        }
        return x2T[s];
    }
};
