class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new LinkedList<List<Integer>>();
        LinkedList<LinkedList<Integer>> queue = new LinkedList<>();
        Arrays.sort(candidates);
        LinkedList<Integer> first = new LinkedList<>();
        first.add(0);
        first.add(-1);
        queue.add(first);
        
        while (!queue.isEmpty()) {
            LinkedList<Integer> node = queue.remove();
            int sum = node.peek();
            int p = node.get(1);
            int last = -1;
            for (int i = p + 1; i < candidates.length; i++) {
                if (last == candidates[i]) {
                    continue;
                }
                if (sum + candidates[i] < target) {
                    LinkedList<Integer> newNode = (LinkedList<Integer>)node.clone();
                    newNode.set(0, sum + candidates[i]);
                    newNode.set(1, i);
                    newNode.add(candidates[i]);
                    queue.add(newNode);
                } else if (sum + candidates[i] == target) {
                    LinkedList<Integer> newNode = (LinkedList<Integer>)node.clone();
                    newNode.remove();
                    newNode.remove();
                    newNode.add(candidates[i]);
                    ans.add(newNode);
                    break;
                } else {
                    break;
                }
                last = candidates[i];
            }
        }
        
        return ans;
    }
}
