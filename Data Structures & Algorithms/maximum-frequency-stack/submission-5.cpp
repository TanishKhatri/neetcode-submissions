class FreqStack {
private:
    unordered_map<int, int> cnt;
    unordered_map<int, stack<int>> stacks;
    int maxCnt;
public:
    FreqStack() : maxCnt(0) {}
    
    void push(int val) {
        cnt[val]++;
        stacks[cnt[val]].push(val);
        maxCnt = max(maxCnt, cnt[val]);
    }
    
    int pop() {
        int val = stacks[maxCnt].top();
        stacks[maxCnt].pop();
        cnt[val]--;
        if (stacks[maxCnt].empty()) {
            stacks.erase(maxCnt);
            maxCnt--;
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