class Solution {
public:
    typedef pair<int,int> pii;
    pii get_min(vector<int> & v , int n){
        int min1 = -1 ,  min2 = -1;
        for(int i=0;i<n;i++){
            if(min1 == -1 || v[i] < v[min1])    min2 = min1 , min1 = i;
            else if(min2 == -1 || v[i] < v[min2])   min2 = i;
        }
        return {min1,min2};
    }    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();        
        for(int row = n-2 ; row>=0 ;row--){
            auto [min1 , min2] = get_min(grid[row+1] , n);
            for(int col = 0 ; col<n ;col++){
                if(min1 != col) grid[row][col] += grid[row+1][min1]; 
                else    grid[row][col] += grid[row+1][min2];
            }
        }
        return *min_element(grid[0].begin() , grid[0].end());
    }
};
