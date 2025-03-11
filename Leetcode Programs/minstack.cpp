class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        int minVal = _stack.empty() ? val : min(val, _stack.top().second);
        _stack.emplace(val, minVal);
    }

    void pop()
    {
        _stack.pop();
    }

    int top()
    {
        return _stack.top().first;
    }

    int getMin() const
    {
        return _stack.top().second;
    }a

private:
    stack<pair<int, int>> _stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
