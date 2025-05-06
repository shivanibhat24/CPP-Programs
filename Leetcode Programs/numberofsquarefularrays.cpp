class Solution {
public:
    int count=0;
    bool check(int a,int b){
        int temp = sqrt(a+b);
        return ((temp*temp) == (a+b));
    }
    void help(int curr,vector<int> arr){
        if(curr>= arr.size()){
            count++;
            return ;
        }
        for(int i= curr;i<arr.size();i++){
            if(i== curr || arr[i]!= arr[curr]){
                swap(arr[curr],arr[i]);
                if(curr==0 || (curr>0 && check(arr[curr-1],arr[curr]))) help(curr+1,arr);
            }
        }
    }
    int numSquarefulPerms(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        help(0,arr);
        return count;
    }
};
