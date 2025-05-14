class Stk {
    vector<int> s;
public:
    Stk() { s.push_back(0); }
    int top() { return s.back(); }
    void pop() { s.pop_back(); }
    int push(int x) {
        s.push_back(x);
        return 1;
    }
    void trim(int x) {
        while (!s.empty() && s.back() > x) pop();
    }
};
class Sol {
    Stk stk;
public:
    int minOps(const vector<int>& a) {
        int op = 0;
        for (int x : a) op = act(x, op);
        return op;
    }
private:
    int act(int x, int op) {
        stk.trim(x);
        if (stk.top() < x) op += stk.push(x);
        return op;
    }
};
class Solution {
public:
    int minOperations(vector<int>& a) {
        Sol sol;
        return sol.minOps(a);
    }
};
