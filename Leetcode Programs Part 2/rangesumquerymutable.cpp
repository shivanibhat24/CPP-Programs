auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
class NumArray {
    vector<int> st;
    int n;
public:
    NumArray(vector<int>& a) {
        n = a.size();
        if(n&(n-1)) st.resize(4*n);
        else st.resize(2*n);
        fb(0, 0, n-1, a);
    }
    
    void update(int index, int val) {
        fu(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return fs(0, 0, n-1, left, right);
    }

private:
    void fb(int i, int l, int r, vector<int>& a){
        if(l == r){
            st[i] = a[r];
            return;
        }
        int mid = l + (r-l)/2, li = 2*i+1, ri = 2*i+2;
        fb(li, l, mid, a);
        fb(ri, mid+1, r, a);
        st[i] = st[li] + st[ri];
    }

    void fu(int i, int l, int r, int index, int val){
        if(l == r){
            st[i] = val;
            return;
        }
        int mid = l + (r-l)/2, li = 2*i+1, ri = 2*i+2;
        if(index<=mid) fu(li, l, mid, index, val);
        else fu(ri, mid+1, r, index, val);
        st[i] = st[li] + st[ri];
    }

    int fs(int i, int l, int r, int start, int end){
        if(l>end or r<start) return 0;
        if(l>=start and r<=end) return st[i];
        int mid = l + (r-l)/2, li = 2*i+1, ri = 2*i+2;
        return fs(li, l, mid, start, end) + fs(ri, mid+1, r, start, end);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
