public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        if(matrix.length == 0) return new ArrayList<Integer>();
        List<Integer> ans = new ArrayList<>();
        return func(matrix, 0, ans);
    }
    public List<Integer> func(int[][] matrix, int s, List<Integer> ans){
        int m = matrix.length, n = matrix[m-1].length;
        if(s > m/2 || s > n/2 || (m%2 == 0 && s==m/2) || (n%2 == 0 && s==n/2)){
            return ans;
        }
        for(int i = s; i<n-s; i++){
            // System.out.println("Top: " +s + "," + i);
            ans.add(matrix[s][i]);
        }
        if(s+1 != m-s-1){
            for(int i = s+1; i<m-s-1; i++){
                // System.out.println("right: " + i + "," + (n-s-1));
                ans.add(matrix[i][n-s-1]);
            }
        }
        if(m-s-1 != s){
            for(int i = n-s-1; i>=s; i--){
                // System.out.println("bottom:" + (m-s-1) + "," + i);
                ans.add(matrix[m-s-1][i]);
            }
        }
        if(s+1 != m-s-1 && s !=n-s-1){
            for(int i = m-s-2; i>=s+1; i--){
                // System.out.println("left: " + i + "," + s);
                ans.add(matrix[i][s]);
            }
        }
        return func(matrix, s+1, ans);
    }
}
