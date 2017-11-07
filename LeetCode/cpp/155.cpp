class MinStack {
public:
    /** initialize your data structure here. */    
    MinStack() {
        _stack = new stack<long>();
    }
    
    void push(int x) {
        if (_stack->empty()) {
            _min = x;
            _stack->push(0);
        } else {
            _stack->push(x - _min);
            if (x < _min) {
                _min = x;
            }
        }
    }
    
    void pop() {
        if (_stack->top() <= 0) {
            _min -= _stack->top();
        }
        _stack->pop();
    }
    
    int top() {
        if (_stack->top() <= 0) {
            return _min;
        } else {
            return _min + _stack->top();
        }
    }
    
    int getMin() {
        return _min;
    }

private:
    stack<long> *_stack;
    long _min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
