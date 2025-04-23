class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& l, vector<vector<int>>& q) {
        unordered_map<int,int>lx,ly,ld,rd;
        vector<int>a;
        vector<vector<int>>dir;
        unordered_set<long>lamp;
        for(auto &i:l){
            long s=(long)i[0]*n+i[1];
            if(!lamp.count(s)){
                lamp.insert(s);
                lx[i[0]]++;
                ly[i[1]]++;
                ld[i[0]-i[1]]++;
                rd[i[0]+i[1]]++;
            }
        }
        dir={{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
        for(auto &i:q){
            int x=i[0],y=i[1];
            if(lx.count(x)||ly.count(y)||ld.count(x-y)||rd.count(x+y)){
                a.push_back(1);
            }
            else{
                a.push_back(0);
                continue;
            }
            for(auto &d:dir){
                int nx=x+d[0],ny=y+d[1];
                if(nx>=0 && nx<n && ny>=0 && ny<n ){  
                    long s=(long)nx*n+ny;
                    if(lamp.count(s)){
                        if(lx.count(nx)){
                            lx[nx]--;
                            if(lx[nx]<1)
                                lx.erase(nx);
                        }
                        if(ly.count(ny)){
                            ly[ny]--;
                            if(ly[ny]<1)
                                ly.erase(ny);
                        }
                        if(ld.count(nx-ny)){
                            ld[nx-ny]--;
                            if(ld[nx-ny]<1)
                                ld.erase(nx-ny);
                        }
                        if(rd.count(nx+ny)){
                            rd[nx+ny]--;
                            if(rd[nx+ny]<1)
                                rd.erase(nx+ny);
                        }
                        lamp.erase(s);
                    }
                }
            }
        }
        return a;
    }
};
