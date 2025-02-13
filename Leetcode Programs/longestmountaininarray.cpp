class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int p1=0,ans=0;
        for(int i=1;i<arr.size()-1;i++)
        {
            if(arr[i]>arr[i-1])
            {
                p1++;
            }
            if(arr[i]==arr[i-1]) p1=0;
            int cnt=0;
            while(i<arr.size()-1 and arr[i+1]<arr[i])
            {
                cnt++;
                i++;
            }
            if(p1>0 and cnt>0) ans=max(ans, p1+cnt+1);
            if(arr[i-1]>=arr[i]) p1=0;
        }
        return ans;
    }
};
