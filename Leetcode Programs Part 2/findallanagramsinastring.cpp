class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    if(s.size()<p.size()){
        return {};
    }
    int sum_o = 0, sum_e = 0, n = p.size(), m = s.size();
    vector<int> ret;
    for(int i=0; i<n; i++){
        if(p[i]&1){
            sum_o += p[i];
        }
        else{
            sum_e += p[i];
        }
    }
    int temp_sum_e = 0, temp_sum_o = 0;
    for(int i=0; i<n; i++){            
        if(s[i]&1){
            temp_sum_o += s[i];
        }
        else{
            temp_sum_e += s[i];
        }
    }
    if(temp_sum_e == sum_e && temp_sum_o == sum_o){
        ret.push_back(0);
    }
    for(int i=n; i<m; i++){
        if(s[i-n]&1){
            temp_sum_o -= s[i-n];
        }
        else{
            temp_sum_e -= s[i-n];
        }
        if(s[i]&1){
            temp_sum_o += s[i];
        }
        else{
            temp_sum_e += s[i];
        }
        if(temp_sum_e == sum_e && temp_sum_o == sum_o){
            ret.push_back(i-n+1);
        }
        
    }
    return ret;
    }
};
