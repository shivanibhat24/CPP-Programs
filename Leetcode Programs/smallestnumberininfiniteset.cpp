class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    unordered_set<int> minSet;
    SmallestInfiniteSet() {
        maxHeap.push(0);
    }    
    int popSmallest() {
        if (minSet.empty()) {
            int smallest = maxHeap.top() + 1;
            maxHeap.push(smallest);
            return smallest;
        }
        int smallest = minHeap.top();
        minSet.erase(smallest);
        minHeap.pop();
        return smallest;
    }    
    void addBack(int num) {
        if (num > maxHeap.top() || minSet.find(num) != minSet.end()) return;
        minHeap.push(num);
        minSet.insert(num);
    }
};
