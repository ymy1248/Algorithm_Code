class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0;
        stack<int> s;
        
        for (int i = 0; i < ops.size(); ++i) {
            if (ops[i] == "C") {
                int last = s.top();
                s.pop();
                sum -= last;
            } else if (ops[i] == "+") {
                int last = s.top();
                s.pop();
                int last2 = s.top();
                s.push(last);
                sum += last + last2;
                s.push(last + last2);
            } else if (ops[i] == "D") {
                int last = s.top();
                int score = 2 * last;
                sum += score;
                s.push(score);
            } else {
                int score = stoi(ops[i]);
                sum += score;
                s.push(score);
            }
        }
        return sum;
    }
};
