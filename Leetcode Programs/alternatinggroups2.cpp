class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& arr, int k) {
        int n = arr.size();
        int ans=0,last=-1;
        for(int i=0;i<k-1;i++){
            if (arr[i]==arr[i+1]){
                last=i;
            }
        }
        if (last==-1){
            ans+=1;
        }
        for(int i=k;i<n;i++){
            if (arr[i]==arr[i-1]){
                last=i-1;
            }
            else{
                if (last<i-k+1){
                    ans+=1;
                }
            }
        }
        vector<int>new_arr;
        for(int j=n-k+1;j<n;j++){
            new_arr.push_back(arr[j]);
        }
        for(int i=0;i<k-1;i++){
            new_arr.push_back(arr[i]);
        }
        last=-1;        
        for(int i=0;i<k-1;i++){
            if (new_arr[i]==new_arr[i+1]){
                last=i;
            }
        }
        if (last==-1){
            ans+=1;
        }
        for(int i=k;i<new_arr.size();i++){
            if (new_arr[i]==new_arr[i-1]){
                last=i-1;
            }
            else{
                if (last<i-k+1){
                    ans+=1;
                }
            }
        }
        return ans;        
    }
};
