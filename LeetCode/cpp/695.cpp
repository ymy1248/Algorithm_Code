class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        count = 0;
        int max = 0;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                area(grid, i, j);
                max = count > max ? count : max;
                count = 0;
            }
        }
        return max;
    }

private:
    int count;
    void area(vector<vector<int>> &grid, int i, int j) {
        if (i >= grid.size() || j >= grid[i].size() || i < 0 || j < 0 || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        count++;
        area(grid, i + 1, j);
        area(grid, i - 1, j);
        area(grid, i, j + 1);
        area(grid, i, j - 1);
        return;
    }
};
