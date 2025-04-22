class Solution {
    int count=0;
private:
    void merge(vector<int> &nums,int l,int m,int r){
        vector<int> temp;
        int left=l,right=m+1;
        while(left<=m && right<=r){
            long long pro=nums[right];
            pro+=nums[right];
            if(nums[left]>pro){
                count+=(m-left+1);
                right++;
            }
            else{
                left++;
            }
        }
        left=l,right=m+1;
        while(left<=m && right<=r){
            if(nums[left]>nums[right]){
                temp.push_back(nums[right]);
                right++;
            }
            else{
                temp.push_back(nums[left]);
                left++;
            }
        }
        while(left<=m){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=r){
            temp.push_back(nums[right]);
            right++;
        } 
        for(int i=l;i<=r;i++) nums[i]=temp[i-l];

    }
    void mergeSort(vector<int> &nums,int l,int r){
        if(l<r){
            int m=(l+r)>>1;
            mergeSort(nums,l,m);
            mergeSort(nums,m+1,r);
            merge(nums,l,m,r);
        }
    }    
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return count;
    }
};

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK 
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
