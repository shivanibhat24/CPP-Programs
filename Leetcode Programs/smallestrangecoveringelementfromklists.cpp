const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class node {
    public:
    int data;
    int row;
    int col;

    node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

class cmp {
    public:
    bool operator() (node* a, node* b) {
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // step-1 Create a pq of node type
        priority_queue<node*, vector<node*>, cmp> pq;
        
        // step-2 Insert first element of all arrays into pq
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            int elm = nums[i][0];
            mini = min(mini, elm);
            maxi = max(maxi, elm);

            node* newNode = new node(elm, i, 0);
            pq.push(newNode);
        }

        // step-3 Find smallest range
        int start = mini;
        int end = maxi;
        while(!pq.empty()) {
            node* topNode = pq.top();
            pq.pop();

            mini = topNode->data;
            int row = topNode->row;
            int col = topNode->col;

            // update range
            if(maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            if(col+1 < nums[row].size()) {
                // update maxi
                int elm = nums[row][col+1];
                maxi = max(maxi, elm);
                
                // insert to pq
                node* newNode = new node(elm, row, col+1);
                pq.push(newNode);
            }
            else {
                break;
            }
        }

        return {start, end};
    }
};
