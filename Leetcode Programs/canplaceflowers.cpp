class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        if(n==0) return true;
        int size = fb.size();
        for(int i=0;i<fb.size();i++){
            if(fb[i] == 0){
                if(i-1 == -1 || (i-1 >= 0 && fb[i-1] == 0)){
                  if(i+1 == size || (i+1 < size && fb[i+1] == 0)){
                    fb[i] = 1;
                    n--;
                    if(n <= 0) return true;
                  }
                }
            }
        }
        if(n <= 0) return true;
        return false;
    }
};
