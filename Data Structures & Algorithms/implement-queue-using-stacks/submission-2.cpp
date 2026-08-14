class MyQueue {
private:
    stack<int> fill;
    stack<int> emp;
public:
    MyQueue() {}
    
    void push(int x) {
        while (!fill.empty()) {
            emp.push(fill.top());
            fill.pop();
        }
        emp.push(x);
        while (!emp.empty()) {
            fill.push(emp.top());
            emp.pop();
        }
    }
    
    int pop() {
        int top = fill.top();
        fill.pop();
        return top;
    }
    
    int peek() {
        return fill.top();
    }
    
    bool empty() {
        return fill.empty();
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