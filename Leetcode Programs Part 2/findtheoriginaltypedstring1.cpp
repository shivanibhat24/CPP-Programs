class Solution {
public:
    int possibleStringCount(string word) {
        unordered_map<int,int>umap;
        int n=word.size();
        int count=0;
        for(int i=0;i<n;i++)
            {
                if(umap[word[i]]>0 && word[i]==word[i-1] && i!=0)
                {
                    count++;
                }
                umap[word[i]]++;
            }
        return count+1;
    }
};
