class FreqStack {
private:
    unordered_map<int, int> cnt;
    vector<stack<int>> stacks;
public:
    FreqStack() {
        stacks.push_back(stack<int>());
    };
    
    void push(int val) {
        cnt[val]++;
        if (cnt[val] >= stacks.size()) {
            stacks.push_back(stack<int>());
        }
        stacks[cnt[val]].push(val);
    }
    
    int pop() {
        int val = stacks.back().top();
        stacks.back().pop();
        cnt[val]--;
        if (stacks.back().empty()) {
            stacks.pop_back();
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */