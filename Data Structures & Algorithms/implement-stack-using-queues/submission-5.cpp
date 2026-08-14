class MyStack {
private:
    queue<int> fill;
    queue<int> emp;
public:
    MyStack() {}
    
    void push(int x) {
        fill.push(x);
    }
    
    int pop() {
        int popped = 0;
        int size = fill.size();
        for(int i = 0; i < size - 1; i++) {
            emp.push(fill.front());
            fill.pop();
        }
        popped = fill.front();
        fill = emp;
        emp = queue<int>();
        return popped;
    }
    
    int top() {
        int top = 0;
        int size = fill.size();
        for(int i = 0; i < size - 1; i++) {
            emp.push(fill.front());
            fill.pop();
        }
        top = fill.front();
        emp.push(fill.front());
        fill = emp;
        emp = queue<int>();
        return top;
    }
    
    bool empty() {
        return fill.empty();    
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */