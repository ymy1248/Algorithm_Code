class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0 || target < matrix[0][0]) {
            return false;
        }
        int colPos = matrix.length - 1;
        
        for (int i = 1; i < matrix.length; i++) {
             if (matrix[i][0] == target) {
                 return true;
             } else if (target < matrix[i][0]) {
                 colPos = i - 1;
                 break;
             }
        }
        // System.out.println(colPos);
        if (Arrays.binarySearch(matrix[colPos], target) < 0) {
            return false;
        } else {
            return true;
        }
    }
}
