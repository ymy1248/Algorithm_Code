#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) {
            return;
        }
        vector<bool> sub(board.size(), false);
        vector<vector<bool>> table(board.size(), sub);
//         for (int i = 0; i < board.size(); ++i) {
//             for (int j = 0; j < board[0].size(); ++j) {
//                 cout << table[i][j] << " ";
//             }
//             cout << endl;
//         }
        
        for (int i = 0; i < board.size(); ++i) {
            if (board[i][0] == 'O') {
                connect(board, new int[2]{i, 0}, table);
            }
            if (board[i][board[0].size() - 1] == 'O') {
                connect(board, new int[2]{i, board[0].size() - 1}, table);
            }
        }
        
        for (int i = 0; i < board[0].size(); ++i) {
            if (board[0][i] == 'O') {
                connect(board, new int[2]{0, i}, table);
            }
            if (board[board.size() - 1][i] == 'O') {
                connect(board, new int[2]{board.size() - 1, i}, table);
            }
        }
        // connect(board, new int[2]{board.size() - 1, 3}, table);
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                // cout << table[i][j] << " ";
                if (table[i][j] == false) {
                    board[i][j] = 'X';
                }
            }
            // cout << endl;
        }
    }

private:
    void connect(vector<vector<char>>& board, int* pos, vector<vector<bool>>& table) {
        if (table[pos[0]][pos[1]] == true) {
            return;
        } else {
            queue<int*> q;
            q.push(pos);
            table[pos[0]][pos[1]] = true;
            
            while (!q.empty()) {
                int* pos = q.front();
                int row = pos[0];
                int col = pos[1];
                delete[] pos;
                // cout << row << ", " << col << endl;
                q.pop();
                
                if (row + 1 < board.size() && board[row + 1][col] == 'O' && table[row + 1][col] == false) {
                    table[row + 1][col] = true;
                    q.push(new int[2]{row + 1, col});
                }
                if (row - 1 >= 0 && board[row - 1][col] == 'O' && table[row - 1][col] == false) {
                    table[row - 1][col] = true;
                    q.push(new int[2]{row - 1, col});
                }
                if (col + 1 < board[row].size() && board[row][col + 1] == 'O' && table[row][col + 1] == false) {
                    table[row][col + 1] = true;
                    q.push(new int[2]{row, col + 1});
                }
                if (col - 1 >= 0 && board[row][col - 1] == 'O' && table[row][col - 1] == false) {
                    table[row][col - 1] = true;
                    q.push(new int[2]{row, col - 1});
                }
            }
        }
    }
};