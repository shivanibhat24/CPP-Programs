template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
  }
  void add(int i, T x){
    while (i <= N){
      BIT[i] += x;
      i += i & -i;
    }
  }
  T get(int i){
    T ans = 0;
    while (i > 0){
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
  T get(int L, int R){
    return get(R) - get(L-1);
  }
};
class Solution {
public:
    vector<int> countOfPeaks(vector<int>& a, vector<vector<int>>& queries) {
        int i,j,k,n,ty,x,y,tmp,o;
        vector<int> ans;
        n=a.size();
        ans.clear();
        binary_indexed_tree<int> bit(n+10);
        for (i=1;i+1<n;i++)
        {
            if ((a[i]>a[i-1])&&(a[i]>a[i+1])) bit.add(i,1);
        }
        for (i=0;i<queries.size();i++)
        {
            ty=queries[i][0];
            x=queries[i][1];
            y=queries[i][2];
            if (ty==1)
            {
                if (y-x+1>=3) tmp=bit.get(x+1,y-1);
                else tmp=0;
                ans.push_back(tmp);
            }
            else
            {
                for (o=x-1;o<=x+1;o++)
                {
                    if ((o>0)&&(o+1<n))
                    {
                        if ((a[o]>a[o-1])&&(a[o]>a[o+1])) bit.add(o,-1);
                    }
                }
                a[x]=y;
                for (o=x-1;o<=x+1;o++)
                {
                    if ((o>0)&&(o+1<n))
                    {
                        if ((a[o]>a[o-1])&&(a[o]>a[o+1])) bit.add(o,1);
                    }
                }
            }
        }
        return ans;
    }
};
