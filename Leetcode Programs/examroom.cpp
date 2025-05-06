struct EmptyRow{
    int start, end;
    int n;
    EmptyRow(int start, int end, int n) : start(start), end(end), n(n){}
    int max_dist() const{ 
        if (start == 0)
            return end;
        if (end == n-1){
            return end - start;
        }
        return (end - start) / 2;
    }
    int middle_seat() const{
        if (start == 0) return 0;
        if (end == n-1) return n-1;
        return (start + end)/2;
    }
    bool operator<(const EmptyRow& other) const{
        if (max_dist() == other.max_dist()){
            return start > other.start;
        }
        return max_dist() < other.max_dist();
    }
};
class ExamRoom {
    map<int,int> empty_rows;
    priority_queue<EmptyRow> heap;
public:
    int n;
    ExamRoom(int n)  : n(n){
        empty_rows[0] = n-1;
        heap.push(EmptyRow(0,n-1,n));
    }
    bool is_valid_row(const EmptyRow& row){
        return empty_rows.count(row.start) && row.end == empty_rows[row.start];
    }
    int seat() {
        while (!heap.empty() && !is_valid_row(heap.top())){
            heap.pop();
        }
        auto& row = heap.top();
        int dist = row.max_dist();
        int start = row.start;
        int end  = row.end;
        int next_seat = row.middle_seat();
        if (next_seat > start){
            empty_rows[start] = next_seat-1;
            heap.push(EmptyRow(start,next_seat-1,n));
        }
        else{
            empty_rows.erase(start);
        }
        if (next_seat < end){
            empty_rows[next_seat+1] = end;
            heap.push(EmptyRow(next_seat+1,end,n));
        }
        heap.pop();
        return next_seat;
    }    
    void leave(int p) {
        auto it = empty_rows.upper_bound(p);
        int start=p,end=p;
        if (it != empty_rows.end() && it->first == p + 1){
            end = it->second;
            it = empty_rows.erase(it);
        }
        if (it != empty_rows.begin() && (--it)->second == p -1){
            start = it->first;
        }
        empty_rows[start] = end;
        heap.push(EmptyRow(start,end,n));
        
    }
};
