class BinaryIndexedTree {
int n;
vector<int> bit;
vector<int> count;
public:
    BinaryIndexedTree(int n) : n(n), bit(n+1,0), count(n+1, 0){}
    void update(int idx, int val, int c)
    {
        for(; idx <= n ; idx += (idx & -idx))
        {
            if(bit[idx] < val)
            {
                count[idx] = c;
            }
            else if (bit[idx] == val)
            {
                count[idx] += c;
            }
            bit[idx] = max(bit[idx], val);
        }
    }
    pair<int, int> query(int idx)
    {
        int ans = 0;
        int cnt = 0;
        for(; idx > 0; idx -= (idx & -idx))
        {
            if(bit[idx] > ans)
            {
                cnt = count[idx];
            }
            else if(bit[idx] == ans)
            {
                cnt += count[idx];
            }
            ans = max(bit[idx], ans);
        }
        return {ans, cnt};
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        int m = arr.size();
        BinaryIndexedTree tree(m);
        for( int x : nums)
        {
            auto it = lower_bound(arr.begin(), arr.end(), x);
            int i = distance(arr.begin(), it) + 1;
            auto[v, cnt] = tree.query(i-1);
            tree.update(i, v+1, max(cnt,1));
        }
        return tree.query(m).second;
    }
};
