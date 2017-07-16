public class Solution {
    public String convert(String s, int numRows) {
        if(numRows>1){
            StringBuilder[] rows = new StringBuilder[numRows];
            for(int i  = 0; i<numRows; i++){
                rows[i] = new StringBuilder();
            }
            for(int i = 0; i<s.length(); i++){
                int index = i%(2*numRows-2);
                if(index < numRows){
                    rows[index].append(s.charAt(i));
                }
                else{
                    rows[numRows-(index-numRows)-2].append(s.charAt(i));
                }
            }
            for(int i = 1;i<numRows;i++){
                rows[0].append(rows[i].toString());
            }
            return rows[0].toString();
        }
        else{
            return s;
        }
        
    }
}
