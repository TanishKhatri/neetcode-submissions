class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (char c: s) {
            if (!brackets.empty()) {
                if (brackets.top() == '(') {
                    if (c == ')') {
                        brackets.pop();
                    } else if (c == ']' || c == '}') {
                        return false;
                    } else {
                        brackets.push(c);
                    }
                } else if (brackets.top() == '[') {
                    if (c == ']') {
                        brackets.pop();
                    } else if (c == ')' || c == '}') {
                        return false;
                    } else {
                        brackets.push(c);
                    }
                } else if (brackets.top() == '{') {
                    if (c == '}') {
                        brackets.pop();
                    } else if (c == ']' || c == ')') {
                        return false;
                    } else {
                        brackets.push(c);
                    }
                }
            } else {
                brackets.push(c);
            }
        }

        if (!brackets.empty()) {
            return false;
        }

        return true;
    }
};
