class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int prime_n = primes.size();
        vector<long> nums(n, 0), idx(prime_n, 0), last_factor(n, 0);
        nums[0] = 1;
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long,long>>> minheap;
        for(int i = 0; i < prime_n; i++)
            minheap.push({primes[i], i});       
        for(int i = 1; i < n; i++) {
            pair<long, long> next = minheap.top(); 
            minheap.pop();
            nums[i] = next.first;
            last_factor[i] = next.second;            
            idx[next.second]++;
            while(last_factor[idx[next.second]] > next.second) {
                idx[next.second]++;
            }            
            minheap.push(pair<long, long>(nums[idx[next.second]] * primes[next.second], next.second));
        }

        return nums.back();
    }
};
