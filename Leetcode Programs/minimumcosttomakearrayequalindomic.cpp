class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        int n = nums.size();
        int lm = (n-1)/2;
        nth_element(nums.begin(), nums.begin()+lm, nums.end());        
        int med = nums[lm];        
        string upper_str = min_larger_palind(med);
        string lower_str = max_smaller_palind(med);        
        int upper = stoi(upper_str), lower = stoi(lower_str);        
        long long res1 = compute(nums, upper), res2 = compute(nums, lower);
   
        return min(res1, res2);
    }    
    string min_larger_palind(int x){
        string s = to_string(x);
        int n = s.size();
        int mid = (n-1)/2;
        string res = s.substr(0, mid+1);        
        for(int it=(n&1?mid-1:mid); it>=0; --it){
            res.push_back(res[it]);
        }        
        if(res>=s)
            return res;        
        for(int i=mid; i>=0; --i){
            char opt = res[i]+1;
            if(opt<='9'){
                res[i] = opt;
                res[n-i-1] = opt;
                return res;
            }
            res[i] = '0';
            res[n-i-1] = '0';
        }        
        return "_";
    }    
    string max_smaller_palind(int x){
        string s = to_string(x);
        int n = s.size();
        int mid = (n-1)/2;
        string res = s.substr(0, mid+1);        
        for(int it=(n&1?mid-1:mid); it>=0; --it){
            res.push_back(res[it]);
        }        
        if(res<=s)
            return res;        
        for(int i=mid; i>=0; --i){
            char opt = res[i]-1;
            if(i>0 && opt>='0' || opt>'0'){
                res[i] = opt;
                res[n-i-1] = opt;
                return res;
            }
            res[i] = '9';
            res[n-i-1] = '9';
        }        
        res.pop_back();
        return res;
    }    
    long long compute(vector<int> &nums, int piv){
        long long res = 0;
        for(int val: nums){
            res += abs(val - piv);
        }
        return res;
    }
};
