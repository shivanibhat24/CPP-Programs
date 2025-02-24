class CustomStack {
public:
    vector<int>stack;
    int top;

    CustomStack(int maxSize) {
        stack.resize(maxSize);
        top=-1;
    }

    void push(int x) {
        if (top==-1||top<stack.size()-1) {
            top++;
            stack[top]=x;
        }
    }

    int pop() {
        if (top!=-1) {
            return stack[top--];
        }
        return -1;
    }

    void increment(int k, int val) {
        for (int i=0;i<min(k,top+1);i++) {
            stack[i] += val;
        }
    }
};
