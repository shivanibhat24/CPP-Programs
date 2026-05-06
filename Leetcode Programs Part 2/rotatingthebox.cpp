class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size();
        int n=boxGrid[0].size();
        vector<vector<char>>box(n,vector<char>(m,'.'));
        for(int i=0;i<m;++i){
            int k=n-1;
            for(int j=n-1;j>=0;--j){
                if(boxGrid[i][j]=='*'){
                    box[j][m-i-1]='*';
                    k=j-1;
                }
                else if(boxGrid[i][j]=='#'){
                    box[k][m-i-1]='#';
                    k--;
                }
            }
        }
        return box;
    }
};
