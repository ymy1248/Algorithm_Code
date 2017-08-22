class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        // System.out.println(Arrays.toString(candidates));
        List<List<Integer>> ans = new LinkedList<List<Integer>>();
        LinkedList<LinkedList<Integer>> deque = new LinkedList<LinkedList<Integer>>();
        int index = 0;
        while(index < candidates.length && candidates[index] < target){
            LinkedList<Integer> first = new LinkedList<>();
            first.add(candidates[index]);
            first.add(candidates[index]);
            deque.add(first);
            index++;
        }
        
        while(!deque.isEmpty()){
            LinkedList<Integer> node = deque.remove();
            int lastNum = node.getLast();
            int pos = Arrays.binarySearch(candidates, lastNum);
            for(int i = pos; i < candidates.length; i++){
                int num = candidates[i];
                int sum = node.peek();
                if(sum + num < target){
                    LinkedList<Integer> newNode = (LinkedList)node.clone();
                    newNode.set(0, sum + num);
                    newNode.add(num);
                    deque.push(newNode);
                } else if(sum + num == target){
                    LinkedList<Integer> newNode = (LinkedList)node.clone();
                    newNode.remove();
                    newNode.add(num);
                    ans.add(newNode);
                }
            }
        }
        if(Arrays.binarySearch(candidates, target) >= 0){
            LinkedList<Integer> newNode = new LinkedList<>();
            newNode.add(target);
            ans.add(newNode);
            // System.out.println("Here");
        }
        return ans;
    }
}
