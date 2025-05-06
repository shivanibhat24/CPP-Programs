class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {    
    vector<pair<int, int>> iv;
    for(int i = 0; i < score.size(); i++){
        iv.push_back({i, score[i]});
    }
    std::sort(iv.begin(), iv.end(), [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });    
    vector<string> out;
    out.resize(score.size());
    for(int i = 0; i < iv.size(); i++){
        if(i == 0){
            out[iv[i].first] = "Gold Medal";
        }
        else if (i == 1){
            out[iv[i].first] = "Silver Medal";
        }
        else if (i == 2){
            out[iv[i].first] = "Bronze Medal";
        }
        else {
            out[iv[i].first] = std::to_string(i+1);
        }
    }
    return out;
    }
};
