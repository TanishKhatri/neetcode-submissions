class MyQueue {
private:
    stack<int> fill;
    stack<int> emp;
public:
    MyQueue() {}
    
    void push(int x) {
       fill.push(x);
    }
    
    int pop() {
        if (emp.empty()) {
            while (!fill.empty()) {
                emp.push(fill.top());
                fill.pop();
            }
        }
        int top = emp.top();
        emp.pop();
        return top;
    }
    
    int peek() {
        if (emp.empty()) {
            while (!fill.empty()) {
                emp.push(fill.top());
                fill.pop();
            }
        }
        return emp.top();
    }
    
    bool empty() {
        return fill.empty() && emp.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */