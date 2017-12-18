class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (size_t row = 0; row < grid.size(); ++row) {
            for (size_t col = 0; col < grid[row].size(); ++col) {
                if (grid[row][col] == '1') {
                    ++count;
                    eliminate(grid, row, col);
                }
            }
        }
        return count;
    }
    
    void eliminate(vector<vector<char>>& grid, size_t row, size_t col) {
        queue<int*> _queue;
        _queue.push(new int[2]{row, col});
        
        while (!_queue.empty()) {
            int* arr = _queue.front();
            _queue.pop();
            grid[arr[0]][arr[1]] = '0';
            if (arr[0] + 1 < grid.size() && grid[arr[0] + 1][arr[1]] == '1') {
                _queue.push(new int[2]{arr[0] + 1, arr[1]});
                grid[arr[0] + 1][arr[1]] = '0';
            }
            if (arr[0] - 1 >= 0 && grid[arr[0] - 1][arr[1]] == '1') {
                _queue.push(new int[2]{arr[0] - 1, arr[1]});
                grid[arr[0] - 1][arr[1]] = '0';
            }
            if (arr[1] + 1 < grid[arr[0]].size() && grid[arr[0]][arr[1] + 1] == '1') {
                _queue.push(new int[2]{arr[0], arr[1] + 1});
                grid[arr[0]][arr[1] + 1] = '0';
            }
            if (arr[1] - 1 >= 0 && grid[arr[0]][arr[1] - 1] == '1') {
                _queue.push(new int[2]{arr[0], arr[1] - 1});
                grid[arr[0]][arr[1] - 1] = '0';
            }
            delete[] arr;
        }
    }
};
