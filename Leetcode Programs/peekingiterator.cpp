class PeekingIterator {
public:
    PeekingIterator(vector<int> nums) : nums(nums), index(0) {
    }
    int peek() {
        return nums[index];
    }
    int next() {
        return nums[index++];
    }
    bool hasNext() {
        return index < nums.size();
    }
private:
    vector<int> nums;  
    int index;          
};
