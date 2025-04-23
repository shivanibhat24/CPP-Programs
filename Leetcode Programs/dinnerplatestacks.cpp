class DinnerPlates {
public:
    DinnerPlates(int capacity) : capacity_(capacity) {}    
    void push(int val) {
        if (not_full_stacks_.empty()) {
            not_full_stacks_.push(stack_positions_.size());
        }
        auto current_stack = not_full_stacks_.top();
        while (stack_positions_.size() <= current_stack) {
            stack_positions_.push_back(0);
        }
        auto& current_position = stack_positions_[current_stack];
        size_t index = current_stack * capacity_ + current_position;
        if (++current_position == capacity_) {
            not_full_stacks_.pop();
        }
        while (stacks_.size() <= index) {
            stacks_.push_back(0);
        }
        stacks_[index] = val;    
    }    
    int pop() {
        while (!stack_positions_.empty() && stack_positions_.back() == 0) {
            stack_positions_.pop_back();
        }
        if (stack_positions_.empty()) {
            return -1;
        }
        return popAtStack(stack_positions_.size() - 1);
    }    
    int popAtStack(int index) {
        if (index >= stack_positions_.size()) {
            return -1;
        }
        size_t& pos = stack_positions_[index];
        if (pos == 0) {
            return -1;
        }
        if (pos == capacity_) {
            not_full_stacks_.push(index);
        }
        return stacks_[(--pos) + index * capacity_];
    }
private:
    std::vector<int> stacks_ = {};
    std::vector<size_t> stack_positions_ = {};
    std::priority_queue<size_t, std::vector<size_t>, std::greater<size_t>> not_full_stacks_ = {};
    const size_t capacity_;
};
