class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][][] boardTable = new boolean[9][9][9];
        // System.out.println(boardTable[0][0][0]);
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                if(board[row][col] != '.'){
                    int num = board[row][col] - '1';
                    if(boardTable[row][col][num] == true){
                        // System.out.println("row:" + row + ", col:" + col);
                        return false;
                    } else{
                        eliminate(boardTable, row, col, num);
                    }
                }
            }
        }
        return true;
    }
    
    public void eliminate(boolean[][][] boardTable,int row, int col, int num){
        Arrays.fill(boardTable[row][col], true);
        for(int i = 0; i<9; i++){
            boardTable[row][i][num] = true;
            boardTable[i][col][num] = true;
        }
        int blockRow = row/3*3;
        int blockCol = col/3*3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                boardTable[blockRow + i][blockCol + j][num] = true;
            }
        }
    }
}
