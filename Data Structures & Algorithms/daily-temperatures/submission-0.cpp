class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> nG;
        for (int i = 0; i < temperatures.size(); i++) {
            if (nG.empty()) {
                nG.push(i);
            } else {
                if (temperatures[nG.top()] < temperatures[i]) {
                    while (!nG.empty() && temperatures[nG.top()] < temperatures[i]) {
                        result[nG.top()] = i - nG.top();
                        nG.pop();
                    }
                } 
                nG.push(i);
            }
        }

        return result;   
    }
};
