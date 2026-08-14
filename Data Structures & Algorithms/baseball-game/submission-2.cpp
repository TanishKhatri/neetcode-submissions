class Solution {
public:
    int calPoints(vector<string>& operations) {
        int res = 0;
        int l = 0;
        vector<int> records(operations.size(), 0);
        for (int i = 0; i < operations.size(); i++) {
            try {
                records[l] = stoi(operations[i]);
                res += records[l];
                l++;
            } catch(...) {
                if (operations[i] == "+") {
                    records[l] = records[l - 1] + records[l - 2];
                    res += records[l];
                    l++;
                } else if (operations[i] == "D") {
                    records[l] = records[l - 1] * 2; 
                    res += records[l];
                    l++;
                } else if (operations[i] == "C") {
                    res -= records[l - 1];
                    l--;
                }
            }
        }

        return res;
    }
};