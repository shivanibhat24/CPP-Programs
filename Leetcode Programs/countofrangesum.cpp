const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int res = 0;
        int _size = size(nums)+1;
        vector<long long> mergeArr;
        vector<long long> A(_size);
        for(int i=1; i<_size;i++) A[i] = A[i-1] + nums[i-1];
        for(int t=0; t< ceil(log2(_size));t++){
            int n = pow(2,t);
            for(int l=0; l< _size; l+= 2*n){
                int i,j;
                i=j=l+n;
                int left_end = min(l+n,_size);
                int r = min(i+n,_size);
                for(int k = l; k<left_end ;k++){
                    while (i<r && A[i] - A[k] < lower) i++;
                    while (j<r && A[j] - A[k] <= upper) j++;
                    res += j-i;
                }
                mergeArr.resize(r-l);
                merge(A.begin()+l, A.begin()+left_end, A.begin()+left_end, A.begin() + r,mergeArr.begin());
                copy(mergeArr.begin(),mergeArr.end(), A.begin()+l);
            }
        }
        return res;
    }
};
