class Fenw {
public:
    int n;
    vector<int> tree;    
    Fenw(int n): n(n), tree(n+1, 0) {}
    void update(int idx, int delta) {
        for(; idx <= n; idx += idx & -idx)
            tree[idx] += delta;
    }
    int query(int idx) {
        int sum = 0;
        for(; idx > 0; idx -= idx & -idx)
            sum += tree[idx];
        return sum;
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int m = sorted.size();
        auto getRank = [&] (int x) -> int {
            return int(lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin()) + 1;
        };
        Fenw fenw1(m), fenw2(m);
        arr1.push_back(nums[0]);
        fenw1.update(getRank(nums[0]), 1);
        arr2.push_back(nums[1]);
        fenw2.update(getRank(nums[1]), 1);
        for (int i = 2; i < n; i++) {
            int x = nums[i];
            int rank = getRank(x);
            int greaterCount1 = arr1.size() - fenw1.query(rank);
            int greaterCount2 = arr2.size() - fenw2.query(rank);            
            if (greaterCount1 > greaterCount2) {
                arr1.push_back(x);
                fenw1.update(rank, 1);
            } else if (greaterCount1 < greaterCount2) {
                arr2.push_back(x);
                fenw2.update(rank, 1);
            } else {
                if (arr1.size() > arr2.size()) {
                    arr2.push_back(x);
                    fenw2.update(rank, 1);
                } else {
                    arr1.push_back(x);
                    fenw1.update(rank, 1);
                }
            }
        }
        vector<int> result;
        result.insert(result.end(), arr1.begin(), arr1.end());
        result.insert(result.end(), arr2.begin(), arr2.end());
        return result;
    }
};
int ddddddd(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);    
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; i++){
        cin >> nums[i];
    }    
    Solution sol;
    vector<int> ans = sol.resultArray(nums);
    for (int num : ans) {
        cout << num << " ";
    }
    return 0;
}
