const int N = 1e5+1;
bool flag = 1;
vector<bool> ans(N,0);
void help() {
    for(int i=0;i<N;i++) {
        if(!ans[i]) {
            for(int j=1;i+j*j<N;j++) ans[i+j*j] = 1;
        }
    }
    flag = 0;
    return;
}
class Solution {
public:
    bool winnerSquareGame(int n) {
        if(flag) help();
        return ans[n];
    }
};
