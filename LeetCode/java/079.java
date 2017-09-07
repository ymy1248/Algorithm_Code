class Solution {
    public boolean exist(char[][] board, String word) {
        if (board.length == 0 || board[0].length == 0) {
            return false;
        }
        char[] wordChar = word.toCharArray();
        boolean[][] memo = new boolean[board.length][board[0].length];
        
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if(search(board, i, j, wordChar, 0, memo)){
                    return true;
                }
            }
        }
        return false;
    }
    
    public boolean search(char[][] board, int i, int j, char[] wordChar, int index, boolean[][] memo) {
        if (index == wordChar.length) {
            return true;
        }
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || memo[i][j] == true) {
            return false;
        }
        if (board[i][j] == wordChar[index]) {
            memo[i][j] = true;
            if (search(board, i - 1, j, wordChar, index + 1, memo) ||
                   search(board, i, j - 1, wordChar, index + 1, memo) ||
                   search(board, i + 1, j, wordChar, index + 1, memo) ||
                   search(board, i, j + 1, wordChar, index + 1, memo)) {
                return true;
            } else {
                memo[i][j] = false;
                return false;
            }
        } else {
            return false;
        }
        
    }
}
