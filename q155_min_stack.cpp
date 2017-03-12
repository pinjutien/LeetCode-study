class MinStack {
        stack<int> min_stack;
        stack<int> current_stack;
    
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if (min_stack.empty() || (x <= min_stack.top()) ) {
            min_stack.push(x);
        }
        current_stack.push(x);
    }
    
    void pop() {
        if (current_stack.top() == min_stack.top()) {
            min_stack.pop();
        }
        
        current_stack.pop();
    }
    
    int top() {
        return current_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
