bool compare(vector<int> &e1, vector<int> &e2){
    return e1[2] < e2[2];
}

class Solution {
public:
    int padre[105], rango[105];

    void makeSet(int v){
      padre[v] = v;
      rango[v] = 0;
    }

    int findSet(int v){
      int ans;
      if(v == padre[v])
        ans = v;
      else{
        padre[v] = findSet(padre[v]);
        ans = padre[v];
      }
      return ans;
    }

    void unionSet(int u, int v){
      u = findSet(u);
      v = findSet(v);

      if(u != v){
        if(rango[u] < rango[v])
          swap(u, v);
        
        padre[v] = u;
        if(rango[u] == rango[v])
          rango[u]++;
      }
    }

    void dfs(int u, int p, vector<vector<pair<int, int>>> &G, vector<bool> &critical, vector<pair<int, int>> &pred){
        int i, v, ind;
        for(i = 0; i < G[u].size(); ++i){
            v = G[u][i].first;
            ind = G[u][i].second;
            if(v != p && critical[ind]){
                pred[v] = {u, ind};
                dfs(v, u, G, critical, pred);
            }
        }
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int i, u, v, cnt = 0, pos, posOrig, curr, cuv;
        bool flag;
        vector<bool> isCritical(edges.size(), false), isNonCritical(edges.size(), false);
        vector<vector<pair<int, int>>> T(n);
        vector<vector<int>>::iterator it, it2;
        vector<pair<int, int>> pred(n, {-1, -1});
        vector<vector<int>> ans(2);

        for(i = 0; i < n; ++i)
            makeSet(i);
        for(i = 0; i < edges.size(); ++i)
            edges[i].push_back(i);

        sort(edges.begin(), edges.end(), compare);

        for(it = edges.begin(); cnt != n - 1; ++it){
            u = (*it)[0];
            v = (*it)[1];

            if(findSet(u) != findSet(v)){
              ++cnt;
              isCritical[it - edges.begin()] = true;
              T[u].push_back({v, it - edges.begin()});
              T[v].push_back({u, it - edges.begin()});
              unionSet(u, v);
            }
        }

        it2 = it;
        while(it2 != edges.end() && (*it2)[2] == (*(it - 1))[2])
            ++it2;

        for(it = edges.begin(); it != it2; ++it){
            u = (*it)[0];
            v = (*it)[1];
            cuv = (*it)[2];
            pos = it - edges.begin();
            if(!isCritical[pos]){
                isCritical[pos] = true;
                dfs(u, -1, T, isCritical, pred);
                isCritical[pos] = false;

                curr = v;
                flag = false;
                //while(pred[curr].first != u){
                while(curr != u){
                    if(edges[pred[curr].second][2] == cuv){
                        flag = true;
                        isNonCritical[pred[curr].second] = true;
                    }
                    curr = pred[curr].first;
                }
                if(flag)
                    isNonCritical[pos] = true;
            }
        }

        for(it = edges.begin(); it != edges.end(); ++it){
            pos = it - edges.begin();
            posOrig = (*it)[3];
            if(isCritical[pos] && isNonCritical[pos])
                ans[1].push_back(posOrig);
            else if(isCritical[pos])
                ans[0].push_back(posOrig);
            else if(isNonCritical[pos])
                ans[1].push_back(posOrig);
        }

        return ans;
    }
};
