class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        for(auto num: target) {
            pq.push(num);
            sum += num;
        }
        while(pq.top() > 1) {
            if((long long)2 * pq.top() - sum < 1 || sum == pq.top()) return false;
            int x = ((long long)2 * pq.top() - sum) % (sum - pq.top());
            if(!x) x = sum - pq.top();
            sum = sum - pq.top() + x;
            pq.pop();
            pq.push(x);
        }
        return true;
    }
};
