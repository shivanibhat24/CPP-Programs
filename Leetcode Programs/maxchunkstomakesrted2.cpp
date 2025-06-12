class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
       int chunk=0;
       vector<int> leftMax(n),rightMin(n+1);
       leftMax[0]=arr[0];
       for(int i=1;i<n;i++){
        leftMax[i]=max(leftMax[i-1],arr[i]);
       }
       rightMin[n]=INT_MAX;
       for(int i=n-1;i>=0;i--){
        rightMin[i]=min(rightMin[i+1],arr[i]);
       }
       for(int i=0;i<n;i++){
        if(leftMax[i]<=rightMin[i+1]){
            chunk++;
        }
       }
       return chunk;
    }
};   
