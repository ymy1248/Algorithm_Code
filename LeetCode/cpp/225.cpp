class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> *pushQ;
    queue<int> *popQ;
    
    MyStack() {
        pushQ = new queue<int>();
        popQ = new queue<int>();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        pushQ->push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n;
        if (pushQ->empty()) {
            while (popQ->size() != 1) {
                pushQ->push(popQ->front());
                popQ->pop();
            }
            n = popQ->front();
            popQ->pop();
            swap(popQ, pushQ);
        } else {
            while (pushQ->size() != 1) {
                popQ->push(pushQ->front());
                pushQ->pop();
            }
            n = pushQ->front();
            pushQ->pop();
        }
        return n;
    }
    
    /** Get the top element. */
    int top() {
        int n;
        if (pushQ->empty()) {
            while (popQ->size() != 1) {
                pushQ->push(popQ->front());
                popQ->pop();
            }
            n = popQ->front();
            swap(popQ, pushQ);
        } else {
            while (pushQ->size() != 1) {
                popQ->push(pushQ->front());
                pushQ->pop();
            }
            n = pushQ->front();
        }
        return n;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return popQ->empty() && pushQ->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
