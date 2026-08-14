class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> checker(9);

        //Row Check
        for (int i = 0; i < 9; i++) {
            fill(checker.begin(), checker.end(), false);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                } else if (checker[board[i][j] - '0' - 1]) {
                    return false;
                } else {
                    checker[board[i][j] - '0' - 1] = true;
                }
            }
        }

        //Column Check
        for (int i = 0; i < 9; i++) {
            fill(checker.begin(), checker.end(), false);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') {
                    continue;
                } else if (checker[board[j][i] - '0'  - 1]) {
                    return false;
                } else {
                    checker[board[j][i] - '0'  - 1] = true;
                }
            }
        }

        //Squares Check
        int i = 0;
        for (int j = 0; j < 9; j += 3) {
            fill(checker.begin(), checker.end(), false);
            for (int r = i; r < i + 3; r++) {
                for (int c = j; c < j + 3; c++) {
                    if (board[r][c] == '.') continue;
                    
                    int val = board[r][c] - '1'; // Use '1' to keep index 0-8
                    if (checker[val]) return false;
                    checker[val] = true;
                }
            }
        }
        return true;
    }
};
