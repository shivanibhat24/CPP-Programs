class MajorityChecker {
public:
    struct Node {
        public:
        int majority, count;
    };
    int maxN;
    vector<int> arr;                    
    vector<Node> seg;                  
    vector<vector<int>> indices; 
    Node merge(Node a, Node b) {
        if(a.majority == b.majority) {
            return {a.majority, a.count + b.count};
        }
        if(a.count > b.count) {
            return {a.majority, a.count - b.count};
        }
        return {b.majority, b.count - a.count};
    }
    void build(int i, int low, int high) {
        if(low == high) {
            Node node; node.majority = arr[low]; node.count = 1;
            seg[i] = node;
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * i + 1, low, mid);
        build(2 * i + 2, mid + 1, high);
        seg[i] = merge(seg[2 * i + 1], seg[2 * i + 2]);
    }
    Node query_util(int i, int low, int high, int l, int r) {
        if(low > r || high < l) {
            Node node; node.majority = 0; node.count = 0;
            return node;
        }
        if(low >= l && high <= r) {
            return seg[i];
        }
        int mid = low + (high - low) / 2;
        Node ll = query_util(2 * i + 1, low, mid, l, r);
        Node rr = query_util(2 * i + 2, mid + 1, high, l, r);
        return merge(ll, rr);
    }
    MajorityChecker(vector<int> &nums) {
        maxN = nums.size();
        arr = nums;
        seg.resize(maxN * 4 + 10);
        int maxi = 0; for(auto it : nums) { maxi = max(maxi, it); }
        indices.resize(maxi + 1);
        for(int i = 0; i < maxN; i++) indices[nums[i]].push_back(i);
        build(0, 0, maxN - 1);
    }
    int query(int left, int right, int threshold) {
        int ele = query_util(0, 0, maxN - 1, left, right).majority;
        auto &v = indices[ele];
        int l = lower_bound(v.begin(), v.end(), left) - v.begin();
        int r = upper_bound(v.begin(), v.end(), right) - v.begin();
        if(r - l < threshold) {
            return -1;
        }
        return ele;
    }
};
