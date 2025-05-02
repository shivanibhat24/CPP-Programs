class Solution {
public:
    string pushDominoes(string dominoes) {
        int i=0,j=0;
        int n = dominoes.size();
        while(i<n){
            if(dominoes[i]!='.') i++;
            else{
                int j=i;
                while(j<n && dominoes[j] == '.') j++;
                int end = j;
                j--;
                char left,right;
                if(i==0) left = 'L';
                else if(i>0) left = dominoes[i-1];
                if(j==n-1) right = 'R';
                else if(j<n-1) right = dominoes[j+1];
                while(i<j){
                    if(left == 'L' && right == 'R'){
                        break;
                    } else if(left!='L' && right != 'R'){
                        if(i>=0 && i<n) dominoes[i] = 'R';
                        if(j>=0 && j<n) dominoes[j] = 'L';
                        i++;
                        j--;
                    }else if(left == 'L' && right == 'L'){
                        while(j>=0 && j>=i) {
                            dominoes[j] = 'L';
                            j--;
                        }
                        break;
                    }else if(left == 'R' && right == 'R'){
                        while(i<=j && i<n) {
                            dominoes[i] = 'R';
                            i++;
                        }
                        break;
                    }
                }
                if(left == 'L' && right == 'L') dominoes[i] = 'L';
                if(left == 'R' && right == 'R') dominoes[i] = 'R';
                i= end;
            }
        }
        return dominoes;
    }
};
