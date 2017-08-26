c class Solution {
    public List<String> letterCombinations(String digits) {
        int length = digits.length();
        List<String> ans = new LinkedList<>();
        StringBuilder sb = new StringBuilder();
        String[] table = new String[10];
        if(length == 0){
            return ans;
        }
        table[2] = "abc";
        table[3] = "def";
        table[4] = "ghi";
        table[5] = "jkl";
        table[6] = "mno";
        table[7] = "pqrs";
        table[8] = "tuv";
        table[9] = "wxyz";
        
        int num = 1;
        int[] len = new int[length];
        int[] ps = new int[length];
        for(int i = 0; i<length; i++){
            char c = digits.charAt(i);
            int n = Character.getNumericValue(c);
            num *= table[n].length();
            len[i] = table[n].length();
            sb.append(table[n].charAt(0));
        }
        ans.add(sb.toString());
        
        int i = 1;
        while(i < num){
            int p = 0;
            ps[0]++;
            while(ps[p] == len[p]){
                ps[p] = 0;
                char c = digits.charAt(p);
                int n = Character.getNumericValue(c);
                sb.setCharAt(p, table[n].charAt(0));
                ps[++p]++;
            }
            char c = digits.charAt(p);
            int n = Character.getNumericValue(c);
            sb.setCharAt(p, table[n].charAt(ps[p]));
            ans.add(sb.toString());
            i++;
        }
        
        return ans;
    }
}
