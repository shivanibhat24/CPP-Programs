class Solution {
public:
	typedef struct {
		int X:6;
		int Y:6;
		int E:8;
		int M:12;
	} Data_t;
    int minMoves(vector<string>& classroom, int energy) {
		int M = classroom.size();
		int N = classroom[0].size();
		int i, j;
		int SX, SY;
		unordered_map<int, int> Map;
		int Count = 0;		
		for(i = 0; i < M; i++)
		{
			for(j = 0; j < N; j++)
			{
				if(classroom[i][j] == 'S')
				{
					SX = i;
					SY = j;
				}
				else if(classroom[i][j] == 'L')
				{
					Map[((i << 16) + j)] = Count++;
				}
			}
		}		
		if(Count == 0)
		{
			return 0;
		}		
        vector<vector<vector<int> > > DP(M, vector<vector<int> >(N, vector<int>(0x1 << Count, -1)));		
		queue<Data_t> Q;
		Data_t Temp;
		Temp.X = SX;
		Temp.Y = SY;
		Temp.E = energy;
		Temp.M = ((0x1 << Count) - 1);		
		Q.push(Temp);		
		Temp.X = -1;
		Q.push(Temp);
		int Move = 0;		
		while(Q.size())
		{
			Temp = Q.front();
			Q.pop();			
			if(Temp.X == -1)
			{
				Move++;				
				if(Q.size())
				{
					Q.push(Temp);
				}				
				continue;
			}				
			if(Temp.M == 0)
			{
				return Move;
			}			
			if(Temp.E)
			{
				Temp.E--;				
				int dx[] = {0, 1, 0, -1};
				int dy[] = {1, 0, -1, 0};				
				for(i = 0; i < 4; i++)
				{
					int X1 = Temp.X + dx[i];
					int Y1 = Temp.Y + dy[i];
					
					if((X1 >= 0) && (X1 < M) && (Y1 >= 0) && (Y1 < N))
					{
						if(classroom[X1][Y1] != 'X')
						{
							Data_t Temp1 = Temp;
							Temp1.X = X1;
							Temp1.Y = Y1;
							
							if(classroom[X1][Y1] == 'R')
							{
								Temp1.E = energy;
							}
							else if(classroom[X1][Y1] == 'L')
							{
								Temp1.M = (Temp1.M & ~(0x1 << Map[((X1 << 16) + Y1)]));
							}							
							if(Temp1.E > DP[X1][Y1][Temp1.M])
							{
								DP[X1][Y1][Temp1.M] = Temp1.E;
							
								Q.push(Temp1);
							}
						}
					}
				}
			}
		}		
		return -1;
    }
};
