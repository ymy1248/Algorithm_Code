// this beat 80% other java submissions
public class Solution {
    public int maxArea(int[] height) {
        int water = 0;
        for(int pL = 0, pR = height.length - 1; pL < pR; ){
            int h = 0;
            if(height[pL] < height[pR]){
                h = height[pL++];
            }else{
                h = height[pR--];
            }
            water = Math.max( h * (pR - pL + 1), water);
        }
        return water;
    }
}
