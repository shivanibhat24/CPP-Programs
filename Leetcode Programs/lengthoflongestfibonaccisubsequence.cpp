class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        map<pair<int,int>,int>indexes;

        for(int i = 2 ;i < n;i++) {
            int start = 0;
            int end = i-1;
            long long reqSum = arr[i];
            long long sum;
            while(start != end) {
                sum = arr[start] + (long long)arr[end];
                if(sum == reqSum) {
                    indexes[{start,end}] = i;
                    start++;
                }
                else if(sum < reqSum) start++;
                else end--;
            }
        }
        int count = 0;
        int maxCount = 0;
        for(auto &it : indexes) {
            count = 2;
            int i=it.first.first,j=it.first.second,k=it.second;
            while((long long)arr[i]+arr[j] == (long long)arr[k]) {
                count++;
                i = j;
                j = k;
                k = indexes[{i,j}];
            }
            if(count > maxCount)maxCount = count;
        }
        return maxCount;
    }
};
