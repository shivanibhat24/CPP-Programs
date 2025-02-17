class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(int i = 0; i<queries.size(); i++){
            bool flag = false;
            for(int j = 0; j<dictionary.size(); j++){
                if(flag==true) break;
                int mismatch = 0; 
                for(int k = 0; k<queries[i].size(); k++){
                    if(queries[i][k]!=dictionary[j][k]) mismatch++;
                    if(mismatch>2) break;
                }
                if(mismatch<=2){
                    ans.push_back(queries[i]);
                    flag = true;
                }
            }
        }
        return ans;
    }
};
