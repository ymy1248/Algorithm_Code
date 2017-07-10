public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] array = new int [95];
        int max = 0;
        
        for(int i = 0; i<s.length(); i++){
            int c = s.charAt(i) - ' ';
            int cLen = array[c];
            Math.max(array[c], max);
            array[c] = 1;
            
            for(int j = 0; j<95; j++){
                int jLen = array[j];
                if(jLen > cLen && cLen > 0){
                    array[j] = 0;
                    max = Math.max(jLen, max);
                } else if(j != c && array[j] > 0){
                    array[j]++;
                }
            }
        }
        
        for(int i = 0; i<95; i++){
            max = Math.max(max, array[i]);
        }
        
        return max;
    }
}
