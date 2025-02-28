class Solution {
public:
    vector<int> representative;
    vector<int> size;

    int doFind(int city){
        if(representative[city] == city){
            return city;
        }

        representative[city] = doFind(representative[city]);
        return representative[city];
    }

    void doUnion(int city1, int city2){
        int rep1 = doFind(city1);
        int rep2 = doFind(city2);

        if(rep1 == rep2){
            return;
        }
        else if(rep1 < rep2){
            size[rep1] += size[rep2];
            representative[rep2] = rep1;
        }
        else{
            size[rep2] += size[rep1];
            representative[rep1] = rep2;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        for(int i = 0 ; i < n ; i++){
            representative.push_back(i);
            size.push_back(1);
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < n ;j++){
                if(isConnected[i][j]){
                    doUnion(i,j);
                }
            }
        }

        int count = 0;

        for(int i = 0 ; i < n ;i++ ){
            if(representative[i] == i){
                count++;
            }
        }

        return count;
    }
};
