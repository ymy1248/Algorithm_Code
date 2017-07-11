c class Solution {
    public String longestPalindrome(String s) {
        if(s.length() == 0 || s.length() == 1){
            return s;
        }
        int iBest = 1;
        int maxLen = 1;
        int even = 0;
        int odd = 1;
        
        for(int i = 1; i < s.length(); i++){
            if(i - even - 1< 0 || s.charAt(i) != s.charAt(i-even-1)){
                even = 0;
            }
            try{
                if(s.charAt(i) == s.charAt(i-even-1)){
                    even += 2;
                    if(maxLen < even){
                        iBest = i;
                        maxLen = even;
                    }
                }
            }
            catch (Exception e){
            }
   
            if(i - odd - 1 < 0 || s.charAt(i) != s.charAt(i-odd-1)){
                odd = 1;
            }
            try{
                if(s.charAt(i) == s.charAt(i-odd-1)){
                    odd += 2;
                    if(maxLen < odd){
                        iBest = i;
                        maxLen = odd;
                    }
                }
            }
            catch (Exception e){
            }
        }
        return s.substring(iBest-maxLen+1, iBest + 1);
    }
}
