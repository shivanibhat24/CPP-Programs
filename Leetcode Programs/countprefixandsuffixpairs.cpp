class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for(int i = 0;i<n-1;i++){
            int k = words[i].size();
            for(int j = i+1;j<n;j++){
                if(words[j].size() < words[i].size())continue;
                // for prefix 
                if(words[j].substr(0,k) != words[i]){
                    continue;
                }
                // for suffix
                int h = words[j].size();
                if(words[j].substr(h-k) != words[i]){
                    continue;
                }
                count++;
            }
        }
        return count;
    }
};
