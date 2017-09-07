class Solution {
    public void setZeroes(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0){
            return;
        }
        int[] rows = new int[matrix.length];
        int[] cols = new int[matrix[0].length];
        
        for (int i = 0; i < matrix.length; i++) {
            if (rows[i] != 1) {
                for (int j = 0; j < matrix[i].length; j++) {
                    if (cols[j] != 1) {
                        if (matrix[i][j] == 0) {
                            setZeros(matrix, i, j, rows, cols);
                            break;
                        }
                    }
                }
            }
        }
    }
    
    public void setZeros(int[][] matrix, int row, int col, int[] rows, int[] cols) {
        if(rows[row] == 0){
            rows[row] = 1;
            for (int i = 0; i < matrix[row].length; i++) {
                if (matrix[row][i] == 0) {
                    setZeros(matrix, row, i, rows, cols);
                } else {
                    matrix[row][i] = 0;
                }
            }
        }
        if(cols[col] == 0) {
            cols[col] = 1;
            for (int i = 0; i < matrix.length; i++) {
                if (matrix[i][col] == 0) {
                    setZeros(matrix, i, col, rows, cols);
                } else {
                    matrix[i][col] = 0;
                }
            }
        }
    }
}
