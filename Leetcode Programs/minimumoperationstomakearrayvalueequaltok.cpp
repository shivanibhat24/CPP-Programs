#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return true;
}();


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        unordered_set<int>st;

        int mn=INT_MAX;

        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
            mn=min(mn,nums[i]);
        }

        if(k>mn) return -1;

        if(st.size()==1){
            if(*st.begin()==k) return 0;
        }

        int ans=0;

        for(auto const & i:st){

            if(i>k) ans++;
        }

        if(ans==0) return -1;

        else return ans;
    }
};
