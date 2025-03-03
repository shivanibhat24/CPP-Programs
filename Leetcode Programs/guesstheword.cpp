/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:

    int findmatch(string w1,string w2){
        int count =0;
        for(int i=0;i<6;i++){
            if(w1[i]==w2[i]) count++;
        }
        return count;
    }
    void findSecretWord(vector<string>& words, Master& master) {
        srand(time(0));
        int n = words.size();
        vector<string> candidates;

        for(auto& word:words){
            candidates.push_back(word);
        }

        while(!candidates.empty()){
            string word = candidates[rand()%candidates.size()];
            int matches = master.guess(word);
            if(matches == 6) return;
            vector<string> temp;
            for(auto& w: candidates){
                if(findmatch(w,word) == matches) temp.push_back(w);
            }
            candidates = temp;

        }


    }
};
