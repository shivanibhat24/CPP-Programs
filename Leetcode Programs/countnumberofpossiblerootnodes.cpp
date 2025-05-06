#define DEBUG
#ifdef DEBUG
#define LOG(x) cout << #x << " : " << x << '\n';
#else
#define LOG(x)
#endif



const int N = int(1E5);
set<int> children[N];
int ans[N][2];
int correctGuesses = 0;

class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for(int i = 0; i < (int)edges.size(); i++)
        {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }        
        for(int i = 0; i < (int)guesses.size(); i++)
        {
            children[guesses[i][0]].insert(guesses[i][1]);
        }        
        dfs(g, 0, -1, 0, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(correctGuesses - ans[i][0] + ans[i][1] >= k)
                cnt++;
        }
        correctGuesses = 0;
        for(int i = 0; i < n; i++)
        {
            ans[i][0] = 0;
            ans[i][1] = 0;
            children[i].clear();
        }    
        return cnt;
    }
private:
    void dfs(vector<vector<int>>& g, int v, int p, int right, int wrong)
    {
        ans[v][0] = right;
        ans[v][1] = wrong;
        int cnt = 0;
        for(int u : g[v])
        {
            if(u != p)
            {
                bool correct = false, incorrect = false;
                if(children[v].find(u) != children[v].end())
                {
                    correctGuesses++;
                    correct = true;
                }
                if(children[u].find(v) != children[u].end())
                    incorrect = true;
                dfs(g, u, v, right + correct, wrong + incorrect);
            }
        }        
    }
};
