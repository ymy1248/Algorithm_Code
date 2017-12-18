class MyQueue {
public:
    stack<int> popS;
    stack<int> pushS;
    
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        pushS.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int n;
        if (!popS.empty()) {
            n = popS.top();
        } else {
            while (!pushS.empty()) {
                popS.push(pushS.top());
                pushS.pop();
            }
            n = popS.top();
        }
        popS.pop();
        return n;
    }
    
    /** Get the front element. */
    int peek() {
        int n;
        if (!popS.empty()) {
            n = popS.top();
        } else {
            while (!pushS.empty()) {
                popS.push(pushS.top());
                pushS.pop();
            }
            n = popS.top();
        }
        return n;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return pushS.empty() && popS.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
