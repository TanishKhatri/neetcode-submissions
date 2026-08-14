class Solution {
public:
    string simplifyPath(string path) {
        int dotCounter = 0;
        vector<char> simple = {'/'};
        for (char c: path) {
            if (c == '/' && simple.back() != '/') {
                if (simple.back() == '.') {
                    if (dotCounter == 1) {
                        simple.pop_back();
                        simple.pop_back();
                        dotCounter = 0;
                    } else if (dotCounter == 2) {
                        simple.pop_back();
                        simple.pop_back();
                        simple.pop_back();
                        while(!(simple.empty()) && simple.back() != '/') {
                            simple.pop_back();
                        }
                        if (!(simple.empty())) {
                            simple.pop_back();
                        }
                        dotCounter = 0;
                    } else {
                        dotCounter = 0;
                    }
                }
                simple.push_back('/');
            } else if (c == '.') {
                dotCounter++;
                simple.push_back(c);
            } else if (c != '/') {
                simple.push_back(c);
                dotCounter = 0;
            }
        }
        
        if (dotCounter == 1) {
            simple.pop_back();
            if (simple.back() != '/') {
                simple.push_back('.');
            } else {
                simple.pop_back();
            }
        } else if (dotCounter == 2) {
            simple.pop_back();
            simple.pop_back();
            if (simple.back() != '/') {
                simple.push_back('.');
                simple.push_back('.');
            } else {
                simple.pop_back();
                while(!(simple.empty()) && simple.back() != '/') {
                    simple.pop_back();
                }
                if (!(simple.empty())) {
                    simple.pop_back();
                }
            }
        }
        
        while (simple.size() > 1 && simple.back() == '/') {
            simple.pop_back();
        }

        if (simple.empty()) {
            simple.push_back('/');
        }

        return string(simple.begin(), simple.end());
    }
};