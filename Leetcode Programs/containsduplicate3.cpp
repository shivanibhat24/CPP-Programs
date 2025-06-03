class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {        
        vector<int> buckets;
        constexpr int BADVALUE = numeric_limits<int>::max();
        int minv = ranges::min(nums);
        int maxv = ranges::max(nums);
        auto getBucketIdx = [valueDiff, minv](int v) {
            return (v-minv)/(valueDiff+1);
        };
        const size_t max_buckets = getBucketIdx(maxv)+1;
        buckets.assign(max_buckets, BADVALUE);
        auto checkBucket = [&] (int bucket_idx, int v) {            
            auto& v2 = buckets[bucket_idx];
            return v2 != BADVALUE && abs(v2 - v) <= valueDiff;
        };
        for(size_t end = 0; end < nums.size(); end++) {   
            if(end > indexDiff) {
                size_t start = end - indexDiff - 1;
                int bucket_idx = getBucketIdx(nums[start]);                
                buckets[bucket_idx] = BADVALUE;
            }
            int bucket_idx = getBucketIdx(nums[end]);
            if(buckets[bucket_idx] != BADVALUE)
                return true;
            if(bucket_idx > 0 && checkBucket(bucket_idx-1, nums[end]))
                return true;
            if(bucket_idx + 1 < max_buckets && checkBucket(bucket_idx+1, nums[end]))
                return true;                        
            buckets[bucket_idx] = nums[end];
        }
        return false;        
    }
   bool containsNearbyAlmostDuplicate2(vector<int>& nums, int indexDiff, int valueDiff) {
      if(nums.empty() || valueDiff < 0){
        return false;
      }
      int minValue = *min_element(nums.begin(), nums.end());
      int maxValue = *max_element(nums.begin(), nums.end());
      int bucketsize = valueDiff + 1;
      int bucketCount = (maxValue - minValue)/bucketsize + 1;
      vector<int> bucket(bucketCount, INT_MAX);
      for(int i = 0; i<nums.size(); i++){
        int bucketIndex = (nums[i] - minValue)/bucketsize;
        if(bucket[bucketIndex]!=INT_MAX && abs(bucket[bucketIndex]- nums[i])<=valueDiff){
            return true;
        }
         if(bucketIndex > 0 && bucket[bucketIndex - 1]!=INT_MAX && 
           abs(bucket[bucketIndex - 1] - nums[i]) <= valueDiff){
            return true;
        }
         if(bucketIndex < bucketCount - 1 && bucket[bucketIndex + 1] != INT_MAX &&
          abs(bucket[bucketIndex + 1] - nums[i]) <= valueDiff){
            return true;
        }
        bucket[bucketIndex] = nums[i];
        if(i >= indexDiff){
            int oldBucketIndex = (nums[i-indexDiff] - minValue) / bucketsize;
            bucket[oldBucketIndex] = INT_MAX;
        }
      }
      return false;
    }
};
