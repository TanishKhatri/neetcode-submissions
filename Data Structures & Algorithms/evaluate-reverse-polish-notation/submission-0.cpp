class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> exp;
        for (string c: tokens) {
            if (c == "+") {
                int a = exp.top();
                exp.pop();
                int b = exp.top();
                exp.pop();
                exp.push(b + a);
            } else if (c == "-") {
                int a = exp.top();
                exp.pop();
                int b = exp.top();
                exp.pop();
                exp.push(b - a);
            } else if (c == "*") {
                int a = exp.top();
                exp.pop();
                int b = exp.top();
                exp.pop();
                exp.push(b * a);
            } else if (c == "/") {
                int a = exp.top();
                exp.pop();
                int b = exp.top();
                exp.pop();
                exp.push(b / a);
            } else {
                exp.push(stoi(c));
            }
        }
        
        return exp.top();
    }
};
