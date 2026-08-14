class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> col;
        for(int i : asteroids) {
            if (col.empty()) {
                col.push(i);
            } else {
                if ((col.top() > 0 && i > 0) || (col.top() < 0 && i < 0)) {
                    col.push(i);
                } else {
                    bool iDestroyed = false;
                    while (!col.empty() && (col.top() > 0 && i < 0)) {
                        if (abs(col.top()) < abs(i)) {
                            col.pop();
                        } else if (abs(col.top() == abs(i))) {
                            col.pop();
                            iDestroyed = true;
                            break;
                        } else {
                            iDestroyed = true;
                            break;
                        }
                    }

                    if (!iDestroyed) {
                        col.push(i);
                    }
                }
            }
        }

        vector<int> res;
        while (!col.empty()) {
            res.push_back(col.top());
            col.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};