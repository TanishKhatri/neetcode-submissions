class FreqStack {
private:
    unordered_map<int, int> cnt;
    vector<int> st;
public:
    FreqStack() {}
    
    void push(int val) {
        cnt[val]++;
        st.push_back(val);
    }
    
    int pop() {
        int index = 0;
        int mostf = 0;
        for (int i = 0; i < st.size(); i++) {
            if (cnt[st[i]] >= mostf) {
                mostf = cnt[st[i]];
                index = i;
            }
        }
        int popped = st[index];
        cnt[popped]--;
        st.erase(st.begin() + index);
        return popped;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */