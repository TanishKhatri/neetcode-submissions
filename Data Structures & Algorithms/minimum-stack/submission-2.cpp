class MinStack {
private:
    stack<int> mins;
    stack<int> s;
public:
    MinStack() {}
    
    void push(int val) {
        s.push(val);
        val = min(val, mins.empty() ? val : mins.top());
        mins.push(val);
    }
    
    void pop() {
        mins.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
