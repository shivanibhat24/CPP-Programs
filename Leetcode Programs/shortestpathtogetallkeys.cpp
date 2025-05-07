class Solution {
public:
    
    int shortestPathAllKeys(vector<string>& grid) {
        int queue[31*31*(1<<6)][3] = {0};
        int visited[31][31][1<<6] = {0};        
        int move[5] = {-1,0,1,0,-1};
        int m = grid.size();
        int n = grid[0].size();
        int l=0,r=0;
        int key = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == '@')
                {
                    queue[r][0] = i;
                    queue[r][1] = j;
                    queue[r++][2] = 0;
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
					key |= 1 << (grid[i][j] - 'a');
				}
            }
        }
        int level = 1;
        while(l<r)
        {
            for(int k=0,size = r-l,x,y,s;k<size;k++)
            {
                x = queue[l][0];
				y = queue[l][1];
				s = queue[l++][2];
                for(int i=0,nx,ny,ns;i<4;i++)
                {
                    nx = x + move[i];
					ny = y + move[i + 1];
					ns = s;
                    if (nx < 0 || nx == m || ny < 0 || ny == n || grid[nx][ny] == '#') {
						continue;
					}
                    if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'F' && ((ns & (1 << (grid[nx][ny] - 'A'))) == 0)) {
						continue;
					}
                    if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'f') {
						ns |= (1 << (grid[nx][ny] - 'a'));
					}
                    if (ns == key) {
						return level;
					}
                    if (!visited[nx][ny][ns]) {
						visited[nx][ny][ns] = true;
						queue[r][0] = nx;
						queue[r][1] = ny;
						queue[r++][2] = ns;
					}
                }
            }
            level++;
        }
        return -1;
    }
};
