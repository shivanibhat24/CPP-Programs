class Solution {
public:
    int minimumRecolors(string& blocks, int k) {
        const int n=blocks.size();
        int W=count(blocks.begin(), blocks.begin()+k, 'W');
        int recolor=W;
        for(int l=0, r=k; r<n; r++, l++){
            W+=(blocks[r]=='W')-(blocks[l]=='W');
            recolor=min(recolor, W);
        }
        return recolor;
    }
};
