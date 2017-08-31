/* *******************
 * beat 90% in leetcode with hashmap
 * ******************/

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        ArrayList<List<String>> ans = new ArrayList<>();
        HashMap<String, Integer> hash = new HashMap<>();
        int index = 0;
        
        for (String str: strs) {
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String sortedStr = new String(chars);
            int addIndex = 0;
            if (hash.containsKey(sortedStr)) {
                addIndex = hash.get(sortedStr);
                ans.get(addIndex).add(str);
            } else {
                addIndex = index;
                hash.put(sortedStr, index++);
                LinkedList<String> list = new LinkedList<>();
                list.add(str);
                ans.add(list);
            }
        }
        return ans;
    }
}
