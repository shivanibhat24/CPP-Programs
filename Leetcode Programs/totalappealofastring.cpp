class Solution {
public:
    long long appealSum(string s) {
        vector<int>arr(27,-1);
        long long ans=0;
        for(int i=0;i<s.length();i++){
            int l=arr[s[i]-'a'];
            ans+=(i-l)*(s.length()-i);
            arr[s[i]-'a']=i;
        }
        return ans;
    }
};
