class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector <int> ans;
        int done = arr.size();
        int finder = done -1;
        while(done > 1){
            for(int i = done-1; i >= 0; i--){
                if(arr[i] == done){
                    ans.push_back(i+1);
                    ans.push_back(done);
                    reverse(arr.begin(),arr.begin()+i+1);
                    reverse(arr.begin(),arr.begin()+done);
                    done--;
                    break;
                }
            }
        }
        return ans;
    }
};
