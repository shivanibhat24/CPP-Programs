class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int i=0,j=1;
        int x=arr[j]-arr[i];
        i++;
        j++;
        while(j<arr.size() && arr[j]-arr[i]==x )
        {
            i++;
            j++;
        }
        if(j==arr.size()) return true;
        else return false;
        
    }
};
