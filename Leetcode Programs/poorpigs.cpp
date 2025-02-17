#pragma GCC optimize("O3")
class Solution {
public:
    int poorPigs(int buckets, int timeDetect, int timeTest) {
        signed x=0, B=timeTest/timeDetect+1, P=1;
        #pragma unroll
        for( ; P<buckets; x++) P*=B;
        return x;
    }
};
