class Solution {
public:
    int numTrees(int n) {
        int table[n + 1] = {1};
        
        for (int i = 1; i <= n; i++) {
            int kind = 0;
            for (int j = 1; j <= i; j++) {
                kind += table[j - 1] * table[i- j];
            }
            table[i] = kind;
        }
        return table[n];
    }
};
