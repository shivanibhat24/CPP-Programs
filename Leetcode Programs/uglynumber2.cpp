class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> result( n );
        result[0] = 1;
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        int next2 = 2;
        int next3 = 3;
        int next5 = 5;
        for( int i = 1; i < n; ++i )
        {
            int next = std::min( next2, std::min( next3, next5 ) );
            result[i] = next;
            if( next == next2 )
            {
                ++i2;
                next2 = result[i2] * 2;
            }
            if( next == next3 )
            {
                ++i3;
                next3 = result[i3] * 3;
            }
            if( next == next5 )
            {
                ++i5;
                next5 = result[i5] * 5;
            }
        }
        return result[n - 1];
    }
};
