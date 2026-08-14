class MinStack {
private:
    long min;
    stack<long> encoded;
public:
    MinStack() {}
    
    void push(int val) {
        if (encoded.empty()) {
            encoded.push(0);
            min = val;
        } else {
            encoded.push(val - min);
            if (val < min) min = val;
        }
    }
    
    void pop() {
        if (encoded.empty()) return;

        long pop = encoded.top();
        encoded.pop();

        if (pop < 0) min = min - pop;
    }
    
    int top() {
        long top = encoded.top();
        return (top > 0) ? (top + min) : (int)min;
    }
    
    int getMin() {
        return (int)min;
    }
};
