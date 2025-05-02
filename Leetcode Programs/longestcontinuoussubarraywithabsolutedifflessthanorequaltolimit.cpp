class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        unsigned int mindex[(uint)1e5], mindex_s = 0, mindex_e = 0;
        unsigned int maxdex[(uint)1e5], maxdex_s = 0, maxdex_e = 0;
        unsigned int max_length = 0;        
        for( auto start = nums.begin(), end = nums.begin(); end < nums.end(); ++end ){
            while( mindex_e > mindex_s && mindex[mindex_e-1] > *end )
                --mindex_e;
            mindex[mindex_e] = *end;
            ++mindex_e;
            while( maxdex_e > maxdex_s && maxdex[maxdex_e-1] < *end )
                --maxdex_e;
            maxdex[maxdex_e] = *end;
            ++maxdex_e;
            while( maxdex[maxdex_s] - mindex[mindex_s] > limit ){
                if( mindex[mindex_s] == *start)
                    ++mindex_s;
                if( maxdex[maxdex_s] == *start)
                    ++maxdex_s;
                ++start;
            }
            if( max_length < end - start ){
                max_length = end - start;
            }
        }
        return max_length + 1;
    }
};
