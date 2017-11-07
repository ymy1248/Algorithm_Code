class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int count = 1;
        bool crash = false;
        vector<vector<int>> b = board;
        
        for (size_t i = 0; i < board.size(); ++i) {
            count = 1;
            for (size_t j = 1; j < board[i].size(); ++j) {
                if (board[i][j] == 0) {
                    count = 1;
                    continue;
                }
                if (board[i][j] == board[i][j - 1]) {
                    count++;
                } else {
                    count = 1;
                }
                if (count == 3) {
                    crash = true;
                    b[i][j] = -1;
                    b[i][j - 1] = -1;
                    b[i][j - 2] = -1;
                } else if (count > 3) {
                    b[i][j] = -1;
                }
            }
        }
        for (size_t j = 0; j < board[0].size(); ++j) {
            count = 1;
            for (size_t i = 1; i < board.size(); ++i) {
                if (board[i][j] == 0) {
                    count = 1;
                    continue;
                }
                if (board[i][j] == board[i - 1][j]) {
                    count++;
                } else {
                    count = 1;
                }
                if (count == 3) {
                    crash = true;
                    b[i][j] = -1;
                    b[i - 1][j] = -1;
                    b[i - 2][j] = -1;
                } else if (count > 3) {
                    b[i][j] = -1;
                }
            }
        }
        if (crash == false) {
            return board;
        }
        for (int i = board.size() - 1; i >= 0; --i) {
            for (int j = board.size() - 1; j >= 0; --j) {
                while (b[i][j] == -1) {
                    for (int k = i; k > 0; --k) {
                        board[k][j] = board[k - 1][j];
                        b[k][j] = b[k - 1][j];
                    }
                    board[0][j] = 0;
                    b[0][j] = 0;
                }
            }
        }
        
        return candyCrush(board);
    }
};
