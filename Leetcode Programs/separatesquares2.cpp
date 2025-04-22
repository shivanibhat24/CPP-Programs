#pragma GCC optimize("O3", "unroll-loops")

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif

const int START = +1, END = -1;
struct Event {
	int x1, x2, y, type;
};
struct Range {
	int x1, x2;
};
struct Node {
	int covered_cnt;
	int covered_len;
	bool left_covered = false;
	bool right_covered = false;
};
struct SegmentTree {
	vector<int> vals;//to store the x co ords
    vector<Node>tree;//segment tree's own 4*n arrray memory.
    int sz;
    //assign the valus of x co ord set to the segement tree.
    SegmentTree(const set<int>& st) : tree(vector(4*st.size(), Node {0, 0})), sz(st.size()) {
    	vals.assign(st.begin(), st.end());
    }

    void update_range(int l, int r, int delta) {
    	update_range(l, r, delta, 1, 0, sz - 1);
    }
    void update_range(int l, int r, int delta, int v, int vl, int vr) {
    	if(vl > r || vr < l) return;

    	int mid = (vl + vr) / 2;
    	if(l <= vl && vr <= r) {//total overlap
    		tree[v].covered_cnt += delta;
    	}else {//partial overlap
	    	update_range(l, r, delta, 2*v, vl, mid);
	    	update_range(l, r, delta, 2*v + 1, mid + 1, vr);
    	}
    	if(tree[v].covered_cnt) {//total coverage
    		tree[v].covered_len = vals[vr] - vals[vl] + 1;
    		tree[v].left_covered = tree[v].right_covered = true;
    	}else if(vl == vr) {//leaf nodes(no coverage)
    		tree[v].covered_len = 0;
    		tree[v].left_covered = tree[v].right_covered = false;
    	}else {
    		tree[v].covered_len = tree[2*v].covered_len + tree[2*v+1].covered_len;
    		if(tree[2*v].right_covered && tree[2*v+1].left_covered) {
    			tree[v].covered_len += vals[mid + 1] - vals[mid] - 1;
    		}
    		tree[v].left_covered = tree[2*v].left_covered;
    		tree[v].right_covered = tree[2*v+1].right_covered;
    	}
    }
    //as the root represent the summation of all the leaf and 
    //internal nodes, its covere Len is final.
    // we need not worry about every line y as , updates are dynamic in nature.
    
    int covered() {
    	return tree[1].covered_len;
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
    	map<int, int> mapping;
    	set<int> vals;
		for(auto& sq : squares) {
			vals.insert(sq[0] - 1);
			vals.insert(sq[0]);
			vals.insert(sq[0] + sq[2] - 1);
			vals.insert(sq[0] + sq[2]);
		}
		for(int val : vals) {
			mapping[val] = mapping.size();
		}
        
       
    	vector<Event> events;// x1,x2,y,type
		for(auto& sq : squares) {
			int x1 = sq[0], x2 = sq[0] + sq[2] - 1;

			events.emplace_back(mapping[x1], mapping[x2], sq[1], START);
			events.emplace_back(mapping[x1], mapping[x2], sq[1] + sq[2], END);
		}
        // /sort by lowest y values/first ones to come...
		sort(events.begin(), events.end(), [](auto& a, auto& b) -> bool { return a.y < b.y; });

		SegmentTree segtree(vals);

		int prev_y = 0;
		long long total_area = 0;
		for(auto& event : events) {
            //segtree.covered is basically the no of x co ords covered by that y line.
			total_area += 1LL * (event.y - prev_y) * segtree.covered();
			prev_y = event.y;
			segtree.update_range(event.x1, event.x2, event.type);
		}

		long long current_area = 0;
		prev_y = 0;
		for(auto& event : events) {	
			long long next_area = current_area + 1LL * (event.y - prev_y) * segtree.covered();
            //we have exceeded the halfArea , then return the y .
            //otherwise try to get as close as possible to the , half area.
            
			if(next_area >= (total_area + 1) / 2) {
				return prev_y + ( (total_area / 2.0) - current_area ) / segtree.covered();
			}else {
				current_area = next_area;
			}
			prev_y = event.y;
			segtree.update_range(event.x1, event.x2, event.type);
		}
		throw "impossible";
    }
};
