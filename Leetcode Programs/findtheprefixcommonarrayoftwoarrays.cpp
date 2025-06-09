class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int f[51];
        for(int i=1;i<=A.size();i++) f[i]=0;
        vector<int> c(A.size(),0);
        for(int i=0;i<A.size();i++) {
            if(++f[A[i]]==2) c[i]++;
            if(++f[B[i]]==2) c[i]++;
            if(i) c[i]+=c[i-1];
        }
        return c;
    }
};
