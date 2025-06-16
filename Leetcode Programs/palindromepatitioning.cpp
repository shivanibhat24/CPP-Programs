class Solution {
public:
    void getAllPartitions(string &s, int start, vector<vector<string>> &partitions, vector<string>& current){
        int n = s.size();
        if(start == n){
            partitions.push_back(current);
            return;
        }
        for(int i= start; i < n; i++){
            bool isPalindrome = true;
            for(int j = start; j < start + (i - start + 1)/2; j++){
                if(s[j] != s[i - (j - start)])
                {
                    isPalindrome = false;
                    break;
                }
            }
            if(isPalindrome){
                current.push_back(s.substr(start, i-start+1));
                getAllPartitions(s, i+1, partitions, current);
                current.pop_back();
            }
        }
    }   
    vector<vector<string>> partition(string s) {
        vector<vector<string>> partitions;
        vector<string> current;
        int start =0;
        getAllPartitions(s, start, partitions, current);
        return partitions;
    }
};
