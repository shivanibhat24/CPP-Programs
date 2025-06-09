class TreeAncestor {
public:
int p[18][600000];
    TreeAncestor(int n, vector<int>& parent) {
           for (int i=0;i<n;i++){
            p[0][i]=parent[i];
        }
        for (int i=1;i<18;i++){
            for (int j=0;j<n;j++){
                if (p[i-1][j]!=-1)p[i][j] = p[i-1][p[i-1][j]];
                else{
                    p[i][j] = -1;
                }
            }
        }
    }  
    int getKthAncestor(int node, int k) {
        for (int i=0;i<18;i++){
            if (node<0)return -1;
            if ((k>>i)&1){
                node=p[i][node];
            }
        }
        return node;        
    }
};
