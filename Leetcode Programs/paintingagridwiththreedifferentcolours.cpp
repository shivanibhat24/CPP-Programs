class Solution {
    static constexpr int MOD = 1e9 + 7;
    static constexpr int RED_OFF = 0;
    static constexpr int GREEN_OFF = 10;
    static constexpr int BLUE_OFF = 20;
    static constexpr int OFFSETS[3]{RED_OFF, GREEN_OFF, BLUE_OFF};
    vector<int> columns;
    void generateColumns(int m, int &col, int last){
        if(m == 0){
            columns.push_back(col);
            return;
        }
        for(int i = 0; i < 3; ++i){
            if(i != last){
                col |= (1 << (m + OFFSETS[i]));
                generateColumns(m - 1, col, i);
                col &= ~(1 << (m + OFFSETS[i]));
            }
        }
    }
    bool match(int col1, int col2){
        return (col1 & col2) == 0;
    }
public:
    int colorTheGrid(int m, int n) {
        columns.reserve(3 * (1 << (m - 1)));
        int tmp = 0;
        generateColumns(m, tmp, -1);
        const int coln = columns.size();
        vector<vector<int>> adjColumns(coln);
        for(int i = 0; i < coln; ++i){
            for(int j = i + 1; j < coln; ++j){
                if(match(columns[i], columns[j])){
                    adjColumns[i].push_back(j);
                    adjColumns[j].push_back(i);
                }
            }
        }
        vector<int> dpPrev(coln);
        vector<int> dpCurr(coln);
        for(int i = 0; i < coln; ++i){
            dpPrev[i] = 1;
        }
        for(int c = 1; c < n; ++c){
            for(int i = 0; i < coln; ++i){
                dpCurr[i] = 0;

                for(int adj : adjColumns[i]){
                    dpCurr[i] = (dpCurr[i] + dpPrev[adj]) % MOD;
                }
            }
            dpPrev.swap(dpCurr);
        }
        int totalNumber = 0;
        for(int i = 0; i < coln; ++i){
            totalNumber = (totalNumber + dpPrev[i]) % MOD;
        }
        return totalNumber;
    }
};
